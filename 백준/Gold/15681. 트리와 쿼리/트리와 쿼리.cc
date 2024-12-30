#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#include <cstring>
#include <set>
using namespace std;

int N, R, Q;
vector<vector<int>> adjList;
vector<int> parent;
vector<vector<int>> children;
vector<int> treeSize;

void makeTree(int currNode)
{
	for (auto next : adjList[currNode])
	{
		if (next != parent[currNode])
		{
			children[currNode].push_back(next);
			parent[next] = currNode;
			makeTree(next);
		}
	}
}

void countSubtreeNodes(int currNode)
{
	treeSize[currNode] = 1;
	for (auto next : children[currNode])
	{
		countSubtreeNodes(next);
		treeSize[currNode] += treeSize[next];
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> R >> Q;

	adjList.resize(N + 1);
	parent.resize(N + 1);
	children.resize(N + 1);
	treeSize.resize(N + 1);

	fill(parent.begin(), parent.end(), -1);

	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	makeTree(R);

	fill(treeSize.begin(), treeSize.end(), 0);
	countSubtreeNodes(R);

	while (Q--)
	{
		int r; cin >> r;
		cout << treeSize[r] << '\n';
	}
}

