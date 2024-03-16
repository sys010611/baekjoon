#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int N, _n;

vector<P> arr; //<숫자, 위치>

int segmentTree[1100000];

long long result = 0;

void PrintTree()
{
	cout << endl;
	for (int i = 1; i <= 2 * N - 1; i++)
	{
		cout << i << " : " << segmentTree[i] << endl;
	}
	cout << endl;
}

/// <summary>
/// 탐색 구간 범위, 노드 번호, 노드 구간 범위
/// </summary>
int GetSum(int L, int R, int nodeNo, int nodeL, int nodeR)
{
	if(R < nodeL || L > nodeR)
		return 0;

	if (L <= nodeL && nodeR <= R)
		return segmentTree[nodeNo];

	int mid = (nodeL + nodeR) / 2;
	return GetSum(L, R, nodeNo*2, nodeL, mid) + GetSum(L, R, nodeNo*2+1, mid+1, nodeR);

}

void UpdateTree(int nodeNo)
{
	nodeNo /= 2;
	while (nodeNo > 0)
	{
		segmentTree[nodeNo] = segmentTree[nodeNo*2] + segmentTree[nodeNo*2+1];
		nodeNo/=2;
	}
}

bool compare(const P& a, const P& b)
{
	if (a.first == b.first) // 숫자가 같은 경우, 인덱스가 작은 것 부터.
	{
		return a.second < b.second;
	}
	else
	{
		return a.first < b.first;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(segmentTree, segmentTree+1100000, 0);

	cin >> _n;

	N = 1;
	while(N<_n)
		N*=2;

	int input;
	for (int i = 0; i < _n; i++)
	{
		cin >> input;
		arr.push_back(P(input, i));
	}

	sort(arr.begin(), arr.end(), compare); //오름차순 정렬

	//for (auto it = arr.begin(); it != arr.end(); it++)
	//	cout << it->first << ", " << it->second << endl;

	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		int idx = it->second;
		//int number = it->first;

		// 오른쪽 구간의 값을 읽어서, 즉 넘어야할 게 몇개인지 세서, result에 누적합. 지금까지 더 작은 숫자만 트리에 넣었으니까.
		result += GetSum(idx+1, N-1, 1, 0, N-1); 

		segmentTree[idx+N] = 1;
		UpdateTree(idx+N);

		//PrintTree();
	}

	cout << result;
}