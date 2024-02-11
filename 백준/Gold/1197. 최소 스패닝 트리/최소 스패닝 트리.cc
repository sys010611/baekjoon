#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge
{
public:
	int cost;
	int v1;
	int v2;
	bool included;

	Edge(int v1, int v2, int cost): cost(cost), v1(v1), v2(v2), included(false) {};
};

bool CompareEdge(Edge& e1, Edge& e2)
{
	return e1.cost < e2.cost;
}

class Graph
{
public:
	int N; // 노드의 개수
	vector<Edge> edgeList;

	vector<int> root;
	
	Graph(int n) : N(n)
	{
		root.resize(N+1);
		fill(root.begin(), root.end(), -1);
	}

	void AddEdge(int u, int v, int cost)
	{
		edgeList.push_back(Edge(u, v, cost));
	}

	int getRoot(int node)
	{
		if (root[node] == -1)
		{
			return node;
		}
		else
		{
			return getRoot(root[node]);
		}
	}

	/// <summary>
	/// 두 정점이 같은 집합에 속해있는지
	/// </summary>
	bool find(int v1, int v2)
	{
		int root1 = getRoot(v1);
		int root2 = getRoot(v2);

		if (root1 == root2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void merge(int v1, int v2)
	{
		int root1 = getRoot(v1);
		int root2 = getRoot(v2);

		root[root2] = root1;
	}

	int Kruskal()
	{
		sort(edgeList.begin(), edgeList.end(), CompareEdge);

		//for (auto it = edgeList.begin(); it != edgeList.end(); it++)
		//{
		//	cout << it->v1 << " " << it->v2 << " " << it->cost << endl;
		//}

		int edgeCount = 0;
		long long treeCost = 0;
		int idx = 0;

		for (auto it = edgeList.begin(); it != edgeList.end(); it++)
		{
			//cout << "현재 간선:  " << it->v1 << " " << it->v2 << endl;

			//cout << "루트 현황: " << endl;
			//for (auto it = root.begin(); it != root.end(); it++)
			//{
			//	cout << *it << " ";
			//}
			//cout << endl;

			if (find(it->v1, it->v2))
			{
				//cout << "루트 같음, 유니온 X" << endl;
				continue;
			}
			else
			{
				//cout << "유니온 수행  " << it->v1 << " " << it->v2 << endl;
				merge(it->v1, it->v2);
				edgeCount++;
				treeCost += it->cost;
				it->included = true;
			}

			if(edgeCount == N-1)
				break;
		}

		return treeCost;
	}
};

int main()
{
	int V, E;

	cin >> V >> E;

	Graph G(V);

	int A,B,C;
	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;

		G.AddEdge(A,B,C);
	}

	//Edge들을 줄세운 다음 비용이 작은 것 부터 하나씩 포함시키기
	cout << G.Kruskal();
}