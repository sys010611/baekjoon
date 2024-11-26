#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

bool visited[501];
bool isComplete[501];
vector<int> prevRank;
vector<set<int>> adjList;

bool DFS(int curr)
{
	if (visited[curr])
	{
		if (!isComplete[curr])
		{
			//cout << "사이클 발견" << endl;
			return true;
		}
		else
		{
			return false;
		}
	}

	visited[curr] = true;

	bool ret = false;
	for (auto next : adjList[curr])
	{
		ret = ret || DFS(next);
	}

	isComplete[curr] = true;
	return ret;
}

void PrintAdjList(int n)
{
	for (int i = 0; i <= n; i++)
	{
		cout << "i : " << i;
		cout << " -> ";
		for (auto next : adjList[i])
			cout << next << " ";
		cout << endl;
	}
}

signed main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(visited, 0, sizeof(visited));
		memset(isComplete, 0, sizeof(isComplete));
		prevRank = vector<int>();
		adjList = vector<set<int>>();

		int n; cin >> n;
		prevRank.resize(n);

		for (int i = 0; i < n; i++)
		{
			cin >> prevRank[i];
		}

		// 그래프 만들기
		adjList.resize(n + 1);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				//cout << prevRank[i] << " -> " << prevRank[j] << endl;
				adjList[prevRank[i]].insert(prevRank[j]);
			}
		}

		//PrintAdjList(n);

		int m; cin >> m;
		while (m--)
		{
			int a, b;
			cin >> a >> b;

			if (adjList[a].find(b) != adjList[a].end())
			{
				adjList[a].erase(b);
				adjList[b].insert(a);
			}
			else if (adjList[b].find(a) != adjList[b].end())
			{
				adjList[b].erase(a);
				adjList[a].insert(b);
			}
		}

		// 사이클 탐지
		bool foundCycle = false;
		for (int i = 1; i <= n; i++)
		{
			if (DFS(i))
			{
				foundCycle = true;
			}
		}
		if (foundCycle)
		{
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		//PrintAdjList(n);

		vector<int> result;
		// 모호성 탐지
		for (int i = n-1; i > -1; i--)
		{
			bool found = false;
			bool inconsistent = false;
			for (int j = 1; j <= n; j++)
			{
				if (adjList[j].size() == i)
				{
					if (!found)
					{
						//cout << n-i <<"등 : " << j << endl;
						result.push_back(j);
						found = true;
					}
					else
					{
						result = vector<int>();
						//cout << "result 비움 " << endl;
						inconsistent = true;
						break;
					}
				}
			}
			if(inconsistent)
				break;
		}

		if (result.empty())
		{
			cout << "?" << endl;
		}
		else
		{
			for(auto item : result)
				cout << item << " ";
			cout << endl;
		}
	}
}
