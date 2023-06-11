#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 100000000
int n, m;

class Graph
{
public:
	int N;
	vector<vector<pair<int, int>>> adjList; //노드, 비용
	vector<bool> visited;
	vector<int> dist;

	Graph(int n) : N(n)
	{
		adjList.resize(N);
		visited.resize(N);
		dist.resize(N);
		fill(dist.begin(), dist.end(), INF);
	}

	void addEdge(int u, int v, int cost)
	{
		adjList[u].push_back({v, cost});
		adjList[v].push_back({u, cost});
	}

	int getMinNode()
	{
		int minDist = INF; int minNode = -1;
		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && dist[i] < minDist)
			{
				minDist = dist[i];
				minNode = i;
			}
		}
		return minNode;
	}

	int prim()
	{
		int minCost = 0;

		int startNode = 0;
		visited[startNode] = true; dist[startNode] = 0;
		for (pair<int,int> adjNode : adjList[startNode])
		{
			dist[adjNode.first] = adjNode.second;
		}

		/*for (auto it = dist.begin(); it != dist.end(); it++)
			cout << *it << " ";*/

		for (int i = 0; i < n - 1; i++)
		{
			int closestNode = getMinNode();
			minCost += dist[closestNode];
			visited[closestNode] = true; 

			for (pair<int, int> adjNode : adjList[closestNode])
			{
				int adjNodeNum = adjNode.first; int distance = adjNode.second;
				if (dist[adjNodeNum] > distance)
					dist[adjNodeNum] = distance;
			}
		}
		return minCost;
	}
};

int main()
{
	cin >> n >> m;

	Graph G(n);

	for (int i = 0; i < m; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;

		G.addEdge(a-1,b-1,c);
	}

	cout << G.prim();
}