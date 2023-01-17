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
	int maxSize = 0; // 컴포넌트 크기의 최댓값

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
				int nodes = dfs(i);
				//cout << "컴포넌트의 크기: " <<  nodes << endl;
				if(nodes > maxSize)
					maxSize = nodes;
				components++;
			}
		}
		return components;
	}

private:
	int dfs(int curr)
	{	
		int nodes = 1;
		if (!visited[curr])
		{
			visited[curr] = true;
			//cout << curr << "번 노드 방문" << endl;
			for (int next : adj[curr])
			{
				if(!visited[next])
					nodes += dfs(next);
			}
		}
		//cout << curr <<"번 노드의 리턴 값: " << nodes << endl;
		return nodes;
	}
};

int main()
{
	int m, n, k;
	cin >> m >> n >> k; //가로길이, 세로길이, 음식물 개수

	vector<pair<int, int>> location(k); //음식물의 위치
	for (int i = 0; i < k; i++)
	{
		cin >> location[i].first >> location[i].second;
	}

	Graph G(k);
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (abs(location[i].first - location[j].first) == 1 && location[i].second == location[j].second) //x축 1차이, y축 동일
			{
				G.addEdge(i, j);
			}
			else if (abs(location[i].second - location[j].second) == 1 && location[i].first == location[j].first) //x축 동일, y축 1차이
			{
				G.addEdge(i, j);
			}
		}
	}

	G.dfsAll();
	cout << G.maxSize;
}