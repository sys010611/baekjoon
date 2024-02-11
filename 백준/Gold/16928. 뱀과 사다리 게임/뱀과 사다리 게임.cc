#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> P;

class Graph
{
public:
	vector<vector<int>> adjList;
	vector<P> portalList;
	vector<bool> visited;

	Graph()
	{
		adjList.resize(106);
		visited.resize(106);
		fill(visited.begin(), visited.end(), false);
	}

	void InitEdge() // 주사위 굴려서 갈 수 있는 칸 할당
	{
		for (int i = 1; i <= 99; i++)
		{
			for (int j = 1; j <= 6; j++)
			{
				AddEdge(i, FindDestination(i + j));
			}
		}
	}

	void AddEdge(int u, int v)
	{
		adjList[u].push_back(v);
	}

	void AddPortal(int u, int v) // u로 도착하면 무조건 v로 가야됨
	{
		portalList.push_back(P(u,v));
	}

	int FindDestination(int v) // 뱀, 사다리 고려한 최종 목적지
	{
		for (auto it = portalList.begin(); it != portalList.end(); it++)
		{
			if (it->first == v)
			{
				return FindDestination(it->second);
			}
		}

		// 포탈 리스트에 v가 없었던 경우 (뱀 / 사다리 없음)
		return v;
	}

	int BFS()
	{
		queue<int> Q;
		Q.push(1);
		visited[1] = true;

		int level = 0;
		while (true)
		{
			int qSize = Q.size();
			while (qSize--)
			{
				int currNode = Q.front(); Q.pop();

				if (currNode == 100) return level;

				for (int nextNode : adjList[currNode])
				{
					if (!visited[nextNode])
					{
						Q.push(nextNode);
						visited[nextNode] = true;
					}
				}
			}
			level++;
		}
	}
};

int main()
{
	Graph G = Graph();

	int N,M; //사다리의 개수 / 뱀의 개수
	cin >> N >> M;

	int x,y;
	for (int i = 0; i < N + M; i++)
	{
		cin >> x >> y;
		G.AddPortal(x, y);
	}

	G.InitEdge(); // 뱀, 사다리를 모두 저장한 뒤 주사위를 통한 인접노드 할당

	cout << G.BFS();
}