#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int indegree[32001];
vector<vector<int>> adjList;
bool visited[32001];

int main()
{
	fill(indegree, indegree + 32001, 0);

	cin >> N >> M;
	adjList.resize(N+1);

	for (int i = 0; i < M; i++)
	{
		int prev, next;
		cin >> prev >> next;

		indegree[next]++;

		adjList[prev].push_back(next);
	}

	queue<int> Q;

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			Q.push(i);
		}
	}

	vector<int> order;

	while (!Q.empty())
	{	
		int currNode = Q.front(); Q.pop();

		order.push_back(currNode);
		for (auto adjNode : adjList[currNode])
		{
			indegree[adjNode]--;
			if (indegree[adjNode] == 0)
			{
				Q.push(adjNode);
			}
		}
	}

	for (auto it = order.begin(); it != order.end(); it++)
	{
		cout << *it << " ";
	}
}