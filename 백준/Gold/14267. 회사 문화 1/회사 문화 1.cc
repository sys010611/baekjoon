#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
vector<vector<int>> adjList;
vector<vector<int>> queries;
vector<int> result;

void DFS(int currNode, int currWeight)
{
	for (auto weight : queries[currNode])
	{
		currWeight += weight;
	}

	result[currNode] = currWeight;


	for (auto next : adjList[currNode])
	{
		DFS(next, currWeight);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	
	adjList.resize(n+1);
	for (int i = 1; i <= n; i++)
	{
		int boss;
		cin >> boss;
		if(boss == -1)	
			continue;
		adjList[boss].push_back(i);
	}

	queries.resize(n+1);
	for (int i = 0; i < m; i++)
	{
		int no, w;
		cin >> no >> w;

		queries[no].push_back(w);
	}

	result.resize(n+1);
	DFS(1, 0);

	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << " ";
	}
}