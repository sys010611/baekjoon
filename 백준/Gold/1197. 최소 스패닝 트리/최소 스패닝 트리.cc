#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int,int> P;

vector<vector<P>> adjList; // cost, nodeNum
bool visited[10001];

int V, E;

int Prim()
{
	int result = 0;

	priority_queue<P, vector<P>, greater<P>> PQ;

	PQ.push(P(0, 1));

	while (!PQ.empty())
	{
		P curr = PQ.top(); PQ.pop();

		int currCost = curr.first;
		int currNode = curr.second;

		if (visited[currNode])
		{
			continue;
		}
		visited[currNode] = true;

		result += currCost;

		for (auto& next : adjList[currNode])
		{
			if (!visited[next.second])
			{
				PQ.push(next);
			}
		}
	}

	return result;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;

	adjList.resize(V+1);

	for (int i = 0; i < E; i++)
	{
		int a,b,c;
		cin>>a>>b>>c;

		adjList[a].push_back(P(c, b));
		adjList[b].push_back(P(c, a));
	}

	cout << Prim();
}
