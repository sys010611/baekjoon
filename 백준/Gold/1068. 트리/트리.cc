#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Tree
{
public:
	int N; //노드의 개수
	vector<int> parent; //각 노드의 부모노드
	vector<vector<int>> children; //각 노드의 자식노드들
	vector<bool> visited; 
	int leafNodeCount = 0;
	int rootNode;

	Tree(int n) //생성자
	{
		N = n;
		parent.resize(N, -1);
		children.resize(N);
		visited.resize(N, false);
	}

	void setChildren(int p, int c)
	{
		if (p != -1)
		{
			parent[c] = p;
			children[p].push_back(c);
		}
		else //부모 노드가 없다 -> 루트 노드
		{
			rootNode = c;
			//cout << "rootNode: " << c << endl;
		}
	}

	void deleteNode(int delNode)
	{
		for (int i = 0; i < N; i++) //자식노드 리스트들에서 해당 노드 제거
		{
			children[i].erase(remove(children[i].begin(), children[i].end(), delNode), children[i].end());
		}
	}

	void dfs(int curr)
	{
		visited[curr] = true;
		//cout << "node " << curr << " visited" << endl;
		if (children[curr].size() == 0)
		{
			leafNodeCount++;
			//cout << "node " << curr << ": leaf node" << endl;
		}

		for (int next : children[curr])
		{
			if (!visited[next])
			{
				dfs(next);
			}
		}
	}
};

int main()
{
	int n;
	cin >> n;
	Tree T(n);

	int p;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		T.setChildren(p,i);
	}

	int delNode;
	cin >> delNode;
	if (delNode == T.rootNode)
	{
		cout << 0;
	}
	else
	{
		T.deleteNode(delNode);
		T.dfs(T.rootNode);
		cout << T.leafNodeCount;
	}
}