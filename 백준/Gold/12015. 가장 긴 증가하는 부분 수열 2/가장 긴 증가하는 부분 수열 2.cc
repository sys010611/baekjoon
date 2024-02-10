#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

int N;

vector<P> v; // <숫자, 인덱스>

int segmentTree[2100000];

bool compare(P a, P b)
{
	if (a.first == b.first)
	{
		return a.second > b.second;
	}

	return a.first < b.first;
}

void PrintPairVector()
{
	cout << "------------------------" << endl;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << "------------------------" << endl;
}

/// <summary>
/// 주어진 범위 내 최댓값을 구한다.
/// </summary>
int GetMaxLength(int L, int R, int nodeL, int nodeR, int nodeIdx)
{
	//cout << "현재 노드 인덱스: " << nodeIdx << endl;
	//printf("현재 노드 범위: %d ~ %d\n", nodeL, nodeR);
	if (R < nodeL || L > nodeR) // 엉뚱한 범위일 경우 0 리턴
	{
		//cout << "범위 잘못됨" << endl;
		return 0;
	}
	
	if (L <= nodeL && nodeR <= R) //노드의 범위를 완전히 포함할 경우
	{
		//cout << "범위 완전 포함 " << endl;
		return segmentTree[nodeIdx];
	}

	//일부만 겹칠 경우: 양 쪽으로 GetMaxLength 재귀호출해서 더 큰 값을 리턴
	//cout << "범위 일부만 겹침" << endl;
	int mid = (nodeL + nodeR) / 2;
	int leftResult = GetMaxLength(L, R, nodeL, mid, nodeIdx * 2);
	int rightResult = GetMaxLength(L, R, mid + 1, nodeR, nodeIdx * 2 + 1);
	return max(leftResult, rightResult);

	//cout << "이게 나오면 뭔가 잘못된 것";
}

/// <summary>
/// 세그먼트 트리를 업데이트한다. 좌우 자식 중 더 큰 값을 부모 노드에 덮어씌운다.
/// </summary>
void UpdateTree(int idx)
{
	idx /= 2;
	while (idx > 0)
	{
		segmentTree[idx] = max(segmentTree[idx*2], segmentTree[idx*2 + 1]);
		idx /= 2;
	}
}

void PrintTree()
{
	for (int i = 1; i <= 15; i++)
	{
		cout << segmentTree[i] << " ";
	}
	cout << endl;
}

int main()
{
	fill(segmentTree, segmentTree + 2100000, 0);

	cin >> N;

	int input;
	for (int i = 1; i <= N; i++) // 편의상 인덱스는 1부터 시작
	{
		cin >> input;
		v.push_back(P(input, i));
	}

	//PrintPairVector();

	sort(v.begin(), v.end(), compare);

	//PrintPairVector();

	int realN = 1;
	while (realN < N)
	{
		realN *= 2;
	}

	for (int i = N+1; i <= realN; i++)
	{
		v.push_back({0, i});
	}

	//PrintPairVector();

	for (auto it = v.begin(); it != v.end(); it++)
	{
		//1 ~ 현재 숫자의 인덱스 범위 내 최대길이 + 1이 곧 현재 인덱스 까지의 최대 길이
		//숫자를 오름차순으로 정렬해놓았기 때문에 가능
		//printf("%d부터 %d까지 범위 내 최장 길이 구하기: \n", 1, it->second);
		segmentTree[it->second + realN - 1] = GetMaxLength(1, it->second, 1, realN, 1) + 1; // 최대길이 저장
		//+realN - 1: 수열의 인덱스를 트리의 인덱스로 변환한 것
		UpdateTree(it->second + realN - 1);

		//PrintTree();
	}

	//printf("\n\n\n\n%d부터 %d까지 범위 내 최장 길이: ", 1, N);
	cout << GetMaxLength(1, N, 1, realN, 1);
}