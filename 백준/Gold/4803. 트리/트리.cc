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
	int edgeCount;
	int componentSize;

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

	Tree makeTree(int startNode)
	{
		Tree T(N);
		int currNode;
		queue<int> Q;
		Q.push(startNode);
		visited[startNode] = true;

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

	void dfs(int startNode)
	{
		int curr = startNode;
		visited[curr] = true;
		componentSize++;
		//cout << "node " << curr << " visited" << endl;
		edgeCount += adjList[curr].size();

		for (int next : adjList[curr])
		{
			if (!visited[next])
			{
				dfs(next);
			}
		}
	}

	int dfsAll()
	{
		int treeCount =0;
		for (int i = 0; i < N; i++)
		{
			if (!visited[i])
			{
				componentSize = 0;
				edgeCount = 0;
				dfs(i);
				edgeCount /= 2;
				//cout << "edgeCount: " << edgeCount << endl;
				//cout << "componentSize: " << componentSize << endl;
				if (componentSize - edgeCount == 1)
					treeCount++;
			}
		}
		return treeCount;
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	while (true)
	{
		int n,m; //노드, 간선
		cin >> n >> m;

		if(n==0 && m == 0)
			return 0;

		Graph G(n);

		int a,b;
		while (m--)
		{
			cin >> a >> b;
			G.addEdge(a-1,b-1);
		}

		int result = G.dfsAll();
		if (result == 0)
		{
			cout << "Case " << T << ": No trees." << endl;
		}
		else if (result == 1)
		{
			cout << "Case " << T << ": There is one tree." << endl;
		}
		else
		{
			cout << "Case " << T << ": A forest of " << result << " trees." << endl;
		}

		T++;
	}
}