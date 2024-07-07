#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<int> candyCounts;
vector<vector<int>> adjList;
vector<bool> visited;
int dp[30000][3001];

pair<int, int> dfs(int curr)
{
	visited[curr] = true;

	int childCount = 1;
	int candyCount = candyCounts[curr];

	// 친구들 사탕까지 전부 합치기
	for (auto next : adjList[curr])
	{
		if (!visited[next])
		{
			auto result = dfs(next);
			childCount += result.first;
			candyCount += result.second;
		}
	}

	return pair<int,int>(childCount, candyCount);
}

void makeComponents(vector<pair<int, int>>& components)
{
	visited.resize(N);
	fill(visited.begin(), visited.end(), false);

	for (int i = 0; i < N; i++)
	{
		if(visited[i])
			continue;

		components.push_back(dfs(i));
	}
}

int main()
{
	cin >> N >> M >> K;
	
	candyCounts.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> candyCounts[i];
	}

	adjList.resize(N);
	for (int i = 0; i < M; i++)
	{
		int a,b;
		cin >> a >> b;
		adjList[a-1].push_back(b-1);
		adjList[b-1].push_back(a-1);
	}

	vector<pair<int,int>> components;
	makeComponents(components);

	//for (auto& component : components)
	//{
	//	cout << "사람 수 : " << component.first << endl;
	//	cout << "사탕 수 : " << component.second << endl;
	//}

	fill(&dp[0][0], &dp[29999][3001], 0);
	
	// 첫번째 컴포넌트에 대해서 dp 계산 (base case)
	int childCount = components[0].first;
	int candyCount = components[0].second;
	for (int i = 0; i <= K; i++)
	{
		if (childCount < i) // 뺏어도 안전한 경우
		{
			dp[0][i] = candyCount;
		}
	}

	// 컴포넌트를 하나씩 추가해가면서 dp 계산
	for (int i = 1; i < components.size(); i++)
	{
		int childCount = components[i].first;
		int candyCount = components[i].second;
		
		for (int j = 0; j <= K; j++) // 상한을 1씩 늘리면서
		{
			if (childCount < j) // 이번 컴포넌트를 사용 가능한 경우
			{
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-childCount] + candyCount);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	cout << dp[components.size()-1][K];
}