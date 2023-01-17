#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
public:
	int N; //노드의 개수
	vector<vector<int>> adj;
	vector<bool> visited;

	Graph(int n)
	{
		N = n;
		adj.resize(N);
		visited.resize(N);
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void sortAdjList()
	{
		for (int i = 0; i < N; i++)
		{
			sort(adj[i].begin(), adj[i].end());
		}
	}

	void dfs()
	{
		fill(visited.begin(), visited.end(), false);
		dfs(0);
	}

	int dfsAll()
	{
		int components = 0;
		fill(visited.begin(), visited.end(), false);
		for (int i = 0; i < N; i++)
		{
			if (!visited[i])
			{
				//cout << " --- dfs start ---" << endl;
				dfs(i);
				components++;
			}
		}
		return components;
	}

private:
	void dfs(int curr)
	{
		if (!visited[curr])
		{
			visited[curr] = true;
			//cout << curr << "번 노드 방문" << endl;
			for (int next : adj[curr])
			{
				dfs(next);
			}
		}
	}
};

int main()
{
	int n,m;
	cin >> n >> m;
	Graph G(n);
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		G.addEdge(u-1, v-1);
	}
	G.sortAdjList();

	
	/*for (int i = 0; i < n; i++)
	{
		cout << i << "노드의 인접노드: ";
		for (vector<int>::iterator it = G.adj[i].begin(); it != G.adj[i].end(); it++)
		{
			cout << *it << ", ";
		}
		cout << endl << endl;
	}*/

	cout << G.dfsAll();
}