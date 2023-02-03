#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

class Tree
{
public:
	int N; //노드의 개수
	vector<int> parent; //각 노드의 부모노드
	vector<vector<int>> children; //각 노드의 자식노드들

	Tree(int n) //생성자
	{
		N = n;
		parent.resize(N, -1);
		children.resize(N);
	}

	void setChildren(int p, int c)
	{
		parent[c] = p;
		children[p].push_back(c);
	}
};

class Graph
{
public:
	int N;
	vector<vector<int>> adjList;
	vector<bool> visited;

	Graph(int n)
	{
		N = n;
		adjList.resize(n);
		visited.resize(n);
	}

	void addEdge(int u, int v)
	{
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	Tree makeTree()
	{
		Tree T(N);
		int currNode;
		queue<int> Q;
		Q.push(0);
		visited[0] = true;

		while (!Q.empty())
		{
			currNode = Q.front();
			Q.pop();
			for (int next : adjList[currNode])
			{
				if (!visited[next])
				{
					Q.push(next);
					visited[next] = true;
					T.setChildren(currNode, next);
				}
			}
		}
		return T;
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;

	Graph G(n);
	
	int a,b;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		G.addEdge(a-1, b-1);
	}

	Tree T = G.makeTree();

	for (int i = 1; i < n; i++)
	{
		cout << T.parent[i]+1 << "\n";
	}
}