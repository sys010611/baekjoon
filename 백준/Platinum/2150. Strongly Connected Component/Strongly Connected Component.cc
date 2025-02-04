#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> P;
#define SIZE 10001

int V, E;
int dfsn[SIZE];
bool finished[SIZE]; // SCC 분리가 끝났는지 여부
vector<vector<int>> adjList;
int cnt = 0;
stack<int> S;
vector<vector<int>> SCCs;

int DFS(int curr)
{
	dfsn[curr] = ++cnt;
	int result = dfsn[curr]; // 나와 내 자식노드에서 도달 가능한 최소 dfsn
	S.push(curr);

	for (auto next : adjList[curr])
	{
		if (dfsn[next] == -1) // 트리 간선
		{
			int low = DFS(next);
			result = min(result, low);
		}
		else // 그 외 (역방향 / 순방향 / 교차)
		{
			if (finished[next]) // SCC가 정해졌다 = 무시 가능
			{
				// 
			}
			else
			{
				result = min(result, dfsn[next]);
			}
		}
	}

	if (result >= dfsn[curr]) //SCC 발견
	{
		vector<int> nodes;

		while (S.top() != curr)
		{
			int node = S.top();
			S.pop();
			finished[node] = true;
			nodes.push_back(node); 
		}
		int node = S.top();
		S.pop();
		finished[node] = true;
		nodes.push_back(node);

		sort(nodes.begin(), nodes.end());
		SCCs.push_back(nodes);
	}

	return result;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dfsn, -1, sizeof(dfsn));
	memset(finished, 0, sizeof(finished));

	cin >> V >> E;
	adjList.resize(V + 1);

	for (int i = 0; i < E; i++)
	{
		int A, B;
		cin >> A >> B;
		adjList[A].push_back(B);
	}

	for (int i = 1; i <= V; i++)
	{
		if (dfsn[i] == -1)
		{
			DFS(i);
		}
	}
	

	sort(SCCs.begin(), SCCs.end());
	cout << SCCs.size() << endl;
	for (auto SCC : SCCs)
	{
		for (auto node : SCC)
		{
			cout << node << " ";
		}
		cout << -1 << endl;
	}
}
