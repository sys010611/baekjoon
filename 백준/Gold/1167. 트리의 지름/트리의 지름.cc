#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Graph
{
public:
	int N;
	vector<vector<pair<int, int>>> adjList; //인접리스트: 인접노드번호, 거리
	vector<bool> visited;

	int maxDistNode;
	int maxDist;
	int currDist;

	Graph(int n) : N(n)
	{
		adjList.resize(N);
		visited.resize(N);
	}

	void addEdge(int u, int v, int dist)
	{
		adjList[u].push_back({ v,dist });
		adjList[v].push_back({ u,dist });
	}

	void initBeforeDfs()
	{
		maxDistNode = -1;
		maxDist = -1;
		fill(visited.begin(), visited.end(), false);
		currDist = 0;
	}


	void dfs(int currNode, int currLen)
	{
		if (visited[currNode]) return;

		visited[currNode] = true;

		currDist += currLen;

		//cout << "현재 노드: " << currNode << endl;
		//cout << "현재 거리: " << currDist << endl;

		if (maxDist < currDist)
		{
			maxDist = currDist;
			maxDistNode = currNode;
		}

		for (pair<int, int>& adjNode : adjList[currNode])
		{
			dfs(adjNode.first, adjNode.second);
		}

		currDist -= currLen;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int v;
	cin >> v;

	Graph G(v);

	for (int i = 0; i < v; i++)
	{
		int stdNode;
		cin >> stdNode;

		while (true)
		{
			int destNode, dist;
			cin >> destNode;

			if (destNode == -1)
				break;
			else
			{
				cin >> dist;
				G.addEdge(stdNode - 1, destNode - 1, dist);
			}
		}
	}

	G.initBeforeDfs();
	G.dfs(0, 0);
	//cout << "0번 노드에서 가장 멀리 떨어진 노드: " << G.maxDistNode << endl;

	int onePoint = G.maxDistNode;

	G.initBeforeDfs();
	G.dfs(onePoint, 0);

	//cout << "거기에서 가장 멀리 떨어진 노드: " << G.maxDistNode << endl;

	cout << G.maxDist;
}