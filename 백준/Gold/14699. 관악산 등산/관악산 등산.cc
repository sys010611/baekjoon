#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> adjList;
vector<int> height;
vector<int> result;
int dp[5001];

int DFS(int curr)
{
	if(dp[curr] != -1)	
		return dp[curr];

	int ret = -1;
	for (auto next : adjList[curr])
	{
		if(height[next] > height[curr])
			ret = max(ret, DFS(next));
	}

	if(ret == -1)
		return 1;

	return dp[curr] = ret+1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fill(dp, dp+5001, -1);

	cin >> N >> M;
	height.resize(N+1);
	adjList.resize(N+1);
	result.resize(N+1);

	for (int i = 1; i <= N; i++)
	{
		cin >> height[i];
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		if(height[a] < height[b])
			adjList[a].push_back(b);
		else
			adjList[b].push_back(a);

	}

	for (int i = 1; i <= N; i++)
	{
		cout << DFS(i) << '\n';
	}
}