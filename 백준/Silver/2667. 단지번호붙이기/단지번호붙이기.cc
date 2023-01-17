#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Graph
{
public:
	int N; //노드의 개수
	vector<vector<int>> adj;
	vector<bool> visited;
	deque<int> componentSizes;

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
				componentSizes.push_back(nodes);
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
	int n;
	cin >> n;

	vector<pair<int, int>> location; // 집이 있는 좌표 저장
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < n; j++)
		{
			if (input[j] == '1')
			{
				location.push_back(make_pair(i,j));
			}
		}
	}

	Graph G(location.size());

	for (int i = 0; i < location.size(); i++)
	{
		for (int j = i + 1; j < location.size(); j++)
		{
			if (location[i].first == location[j].first && abs(location[i].second - location[j].second) == 1)
			{
				G.addEdge(i, j);
			}
			else if (location[i].second == location[j].second && abs(location[i].first - location[j].first) == 1)
			{
				G.addEdge(i, j);
			}
		}
	}

	G.sortAdjList();
	cout << G.dfsAll() << endl;
	sort(G.componentSizes.begin(), G.componentSizes.end());
	while (!G.componentSizes.empty())
	{
		cout << G.componentSizes.front() << endl;
		G.componentSizes.pop_front();
	}
}