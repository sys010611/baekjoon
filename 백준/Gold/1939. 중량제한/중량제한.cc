#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
public:
	int N;
	vector<vector<pair<int,int>>> adjList; // <노드, 가능 중량>
	vector<bool> visited;
	int facA,facB;

	Graph(int n): N(n)
	{
		adjList.resize(N);
		visited.resize(N);
	}

	void addEdge(int u, int v, int cost)
	{
		adjList[u].push_back({ v,cost });
		adjList[v].push_back({ u,cost });
	}

	void setFac(int a, int b)
	{	
		facA = a;
		facB = b;
	}

	//bfs로 운송 시도
	bool Check(int weight)
	{
		fill(visited.begin(), visited.end(), false);

		queue<int> Q;
		Q.push(facA);
		visited[facA] = true;

		while (!Q.empty())
		{
			int curr = Q.front(); Q.pop();
			
			if (curr == facB)
				return true;

			for (auto adj : adjList[curr])
			{
				int adjNode = adj.first;
				int capacity = adj.second;
				if(!visited[adjNode] && weight <= capacity)
				{
					visited[adjNode] = true;
					Q.push(adjNode);
				}
			}
		}

		// 도착하지 못한 채로 큐가 비었다면 실패
		return false;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	Graph G(N);

	for (int i = 0; i < M; i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		G.addEdge(a-1, b-1, c);
	}

	int facA;
	int facB;
	cin >> facA >> facB;
	G.setFac(facA-1, facB-1);

	int lo = 0;
	int hi = 1000000001;
	while (lo + 1 < hi)
	{
		int mid = (lo+hi)/2;

		if (G.Check(lo) == G.Check(mid))
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	cout << lo;
}