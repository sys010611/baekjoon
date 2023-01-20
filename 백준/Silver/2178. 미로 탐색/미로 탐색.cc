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

	int bfs(int v)
	{
		int level = 0;
		queue<int> Q;
		Q.push(v);
		visited[v] = true;
		while (!Q.empty())
		{
			//cout << "level: " << level << endl;
			int qSize = Q.size();
			for(int i=0; i<qSize; i++)
			{
				int curr = Q.front();
				Q.pop();
				//cout << "node " << curr << " visited" << endl;
				if(curr == N-1)
					return level;
				for (int next : adj[curr])
				{
					if (!visited[next])
					{
						Q.push(next);
						visited[next] = true;
					}
				}
			}
			level++;
		}
		return 0;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;

	vector<pair<int,int>> points;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			if (input[j] == '1')
			{
				points.push_back(make_pair(i, j));
			}
		}
	}

	Graph G(points.size());
	for (int i = 0; i < points.size(); i++)
	{
		for (int j = i + 1; j < points.size(); j++)
		{
			if (points[i].first == points[j].first && abs(points[i].second - points[j].second) == 1)
			{
				G.addEdge(i,j);
			}
			else if (abs(points[i].first - points[j].first) == 1 && points[i].second == points[j].second)
			{
				G.addEdge(i, j);
			}
		}
	}

	G.sortAdjList();
	cout << G.bfs(0)+1;
}