#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> P;

int N;
P arr[200000];
int leftTopCount[200000]; // 왼쪽에서 오른쪽으로 쓸면서, 내 왼쪽 위에 있는 점들의 개수를 저장
int rightTopCount[200000]; // 오른쪽에서 왼쪽으로 쓸면서, 내 오른쪽 위에 있는 점들의 개수를 저장

int segTreeL[1048575];
int segTreeR[1048575];

queue<int> treeL_updateQ;
queue<int> treeR_updateQ;

bool compare(P a, P b)
{
	if(a.first == b.first) //x좌표가 같다면 y좌표가 낮은 순으로 정렬
		return a.second < b.second;

	return a.first < b.first; // x좌표 상 왼쪽 순으로 정렬
}


int GetSumL(int L, int R, int nodeNo, int nodeL, int nodeR)
{
	if (L <= nodeL && nodeR <= R)
		return segTreeL[nodeNo];
	
	if(R < nodeL || L > nodeR)
		return 0;

	int mid = (nodeL + nodeR) / 2;
	return GetSumL(L, R, nodeNo*2, nodeL, mid) + GetSumL(L, R, nodeNo * 2 + 1, mid+1, nodeR);
}

int GetSumR(int L, int R, int nodeNo, int nodeL, int nodeR)
{
	if (L <= nodeL && nodeR <= R)
		return segTreeR[nodeNo];

	if (R < nodeL || L > nodeR)
		return 0;

	int mid = (nodeL + nodeR) / 2;
	return GetSumR(L, R, nodeNo * 2, nodeL, mid) + GetSumR(L, R, nodeNo * 2 + 1, mid + 1, nodeR);
}

void Update(int n, bool isLeft)
{
	n /= 2;
	while (n > 0)
	{
		if (isLeft)
		{
			segTreeL[n] = segTreeL[2 * n] + segTreeL[2 * n + 1];
		}
		else
		{
			segTreeR[n] = segTreeR[2 * n] + segTreeR[2 * n + 1];
		}
		n /= 2;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(segTreeL, 0, sizeof(segTreeL));
	memset(segTreeR, 0, sizeof(segTreeR));

	cin >> N;

	int treeN = 524288; // 트리의 리프노드 개수

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		arr[i].second += 200000; // y좌표 범위를 0 ~ 400000로 재조정
	}

	sort(arr, arr + N, compare);

	// x축 상 왼쪽에서 오른쪽으로 스캔, 각 점마다 내 왼쪽 위에 몇개의 점이 있는지 저장
	int lastX = -500000;
	//cout << "왼쪽 -> 오른쪽 스캔 " << endl;
	for (int i = 0; i < N; i++)
	{
		int x = arr[i].first;
		int y = arr[i].second;

		//cout << x << " , " << y << endl;

		if (x != lastX) // x값이 달라지면, 그 때 트리를 업데이트. 같은 x축 상에 있는 것이 트리에 들어가면 에러 발생.
		{
			while (!treeL_updateQ.empty())
			{
				int n = treeL_updateQ.front(); treeL_updateQ.pop();
				segTreeL[n] += 1;
				Update(n, true);
			}
			lastX = x;
		}
		
		leftTopCount[i] = GetSumL(y+1, treeN-1, 1, 0, treeN-1);
		//cout << i << "번째 점 기준 ";
		//cout << "왼쪽 위 점의 개수 : " << leftTopCount[i] << endl;
		treeL_updateQ.push(treeN + y);
	}
	//PrintTree(treeN, true);

	// x축 상 오른쪽에서 왼쪽으로 스캔, 각 점마다 내 오른쪽 위에 몇개의 점이 있는지 저장
	lastX = -500000;
	//cout << "오른쪽 -> 왼쪽 스캔 " << endl;
	for (int i = N-1; i >= 0; i--)
	{
		int x = arr[i].first;
		int y = arr[i].second;

		//cout << x << " , " << y << endl;

		if (x != lastX) // x값이 달라지면, 그 때 트리를 업데이트. 같은 x축 상에 있는 것이 트리에 들어가면 에러 발생.
		{
			while (!treeR_updateQ.empty())
			{
				int n = treeR_updateQ.front(); treeR_updateQ.pop();
				segTreeR[n] += 1;
				Update(n, false);
			}
			lastX = x;
		}

		rightTopCount[i] = GetSumR(y+1, treeN - 1, 1, 0, treeN - 1);
		//cout << i << "번째 점 기준 ";
		//cout << "오른쪽 위 점의 개수 : " << rightTopCount[i] << endl;
		treeR_updateQ.push(treeN+y);
	}
	//PrintTree(treeN, false);

	long long result = 0;
	for (int i = 0; i < N; i++)
	{
		result += ((long long)leftTopCount[i] * rightTopCount[i]) % 1000000007;
		result %= 1000000007;
	}

	cout << result;
}


