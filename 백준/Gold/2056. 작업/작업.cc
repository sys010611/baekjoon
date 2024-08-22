#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N;
int dp[10001];
vector<int> indegrees;
vector<vector<int>> nextList;
vector<vector<int>> prevList;
vector<int> neededTime;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fill(dp, dp+10001, -1);

	cin >> N;
	indegrees.resize(N+1);
	fill(indegrees.begin(), indegrees.end(), 0);
	neededTime.resize(N+1);
	nextList.resize(N+1);
	prevList.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> neededTime[i];
		
		int indegreeCount;
		cin >> indegreeCount;
		for (int j = 0; j < indegreeCount; j++)
		{
			int node; cin >> node; // 선행 작업
			nextList[node].push_back(i);
			prevList[i].push_back(node);
			indegrees[i]++;
		}
	}

	queue<int> Q;
	for (int i = 1; i <= N; i++)
	{
		if(indegrees[i] == 0)
			Q.push(i);
	}

	while (!Q.empty())
	{
		int curr = Q.front(); Q.pop();
		//cout << "현재 작업 : " << curr << endl;

		if (!prevList[curr].empty())
		{	
			int prevTime = -1;
			for (auto prev : prevList[curr])
			{
				prevTime = max(prevTime, dp[prev]);
			}
			dp[curr] = prevTime + neededTime[curr];
		}
		else
		{
			dp[curr] = neededTime[curr];
		}

		for (auto next : nextList[curr])
		{
			indegrees[next]--;
			if (indegrees[next] == 0)
			{
				Q.push(next);
				//cout << "할 수 있게 된 작업 : " << next << endl;
			}
		}
	}

	//for (int i = 1; i <= N; i++)
	//{
	//	printf("작업 %d가 끝나는 시간 : %d\n", i, dp[i]);
	//}

	cout << *max_element(dp, dp + N+1);
}