#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <tuple>
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

	int bfs(int s, int e)
	{
		int level = 0;
		queue<int> Q;
		Q.push(s);
		visited[s] = true;
		while (!Q.empty())
		{
			//cout << "level: " << level << endl;
			int qSize = Q.size();
			for(int i=0; i<qSize; i++)
			{
				int curr = Q.front();
				if (curr == e)
				{
					return level;
				}
				Q.pop();
				//cout << "node " << curr << " visited" << endl;
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
		return -1; //출구를 찾지 못한 경우
	}
};

int main()
{
	while (true)
	{
		int z, y, x; //층수, 세로, 가로
		cin >> z >> y >> x;
		if (x == 0 && y == 0 && z == 0)
			return 0;

		int startNodeNum, FinishNodeNum; //시작점과 도착점의 좌표 저장

		vector<tuple<int, int, int>> points;

		for (int i = 0; i < z; i++) //각 층
		{
			for (int j = 0; j < y; j++) // 각 열
			{
				string input;
				cin >> input;
				for (int p = 0; p < x; p++) //각 열의 각 행
				{
					if (input[p] == 'S')
					{
						points.push_back({ p, j, i });
						startNodeNum = points.size() - 1;
					}
					else if (input[p] == '.')
					{
						points.push_back({ p,j,i });
					}
					else if (input[p] == 'E')
					{
						points.push_back({ p,j,i });
						FinishNodeNum = points.size() - 1;
					}
				}
			}
		}

		Graph G(points.size());
		for (int i = 0; i < points.size(); i++)
		{
			for (int j = i + 1; j < points.size(); j++)
			{
				if (get<2>(points[i]) == get<2>(points[j]) && get<0>(points[i]) == get<0>(points[j]) && abs(get<1>(points[i]) - get<1>(points[j])) == 1) //y축만 1차이
				{
					G.addEdge(i, j);
				}
				else if (get<2>(points[i]) == get<2>(points[j]) && abs(get<0>(points[i]) - get<0>(points[j])) == 1 && get<1>(points[i]) == get<1>(points[j])) //x축만 1차이
				{
					G.addEdge(i, j);
				}
				else if (abs(get<2>(points[i]) - get<2>(points[j])) == 1 && get<0>(points[i]) == get<0>(points[j]) && get<1>(points[i]) == get<1>(points[j])) //z축만 1차이
				{
					G.addEdge(i, j);
				}
			}
		}

		G.sortAdjList();
		int result = G.bfs(startNodeNum, FinishNodeNum);
		if (result == -1)
		{
			cout << "Trapped!" << endl;
		}
		else
		{
			cout << "Escaped in " << result << " minute(s)." << endl;
		}
	}
}
