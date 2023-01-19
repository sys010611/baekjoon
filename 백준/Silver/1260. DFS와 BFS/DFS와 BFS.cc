#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Graph
{
public:
	int N;
	vector<bool> visited;
	vector<vector<int>> adj;

	Graph(int n)
	{
		N = n;
		visited.resize(N);
		adj.resize(N);
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void sortAdjList()
	{
		for (int i = 0; i < adj.size(); i++)
		{
			sort(adj[i].begin(), adj[i].end());
		}
		fill(visited.begin(), visited.end(), false);
	}

	void dfs(int v)
	{
		visited[v] = true;
		cout << v+1 << " ";
		for (int next : adj[v])
		{
			if (!visited[next])
			{
				dfs(next);
			}
		}
	}

	void bfs(int v)
	{
		queue<int> Q;
		Q.push(v);
		visited[v] = true;
		while (!Q.empty())
		{
			int curr = Q.front();
			Q.pop();
			cout << curr+1 << " ";
			for (int next : adj[curr])
			{
				if (!visited[next])
				{
					Q.push(next);
					visited[next] = true;
				}
			}
		}
	}
};

int main()
{
	int n,m,v;
	cin >> n >> m >> v;
	Graph G(n);
	
	for (int i = 0; i < m; i++)
	{
		int u,v;
		cin >> u >> v;
		G.addEdge(u-1 ,v-1);
	}

	G.sortAdjList();
	G.dfs(v-1);
	cout << endl;
	G.sortAdjList();
	G.bfs(v-1);
}