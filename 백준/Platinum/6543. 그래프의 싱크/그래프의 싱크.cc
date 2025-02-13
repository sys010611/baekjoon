#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define MAX 5001

int n, m;
vector<vector<int>> adjList;
vector<vector<int>> SCC;
int dfsn[MAX];
bool finished[MAX];
int sccn[MAX];
int cnt;
stack<int> S;
int sccCnt;
int sccOutdegree[MAX];

void Init()
{
	adjList = vector<vector<int>>();
	memset(dfsn, -1, sizeof(dfsn));
	memset(finished, 0, sizeof(finished));
	memset(sccn, -1, sizeof(sccn));
	memset(sccOutdegree, 0, sizeof(sccOutdegree));
	SCC = vector<vector<int>>();
	cnt = 0;
	S = stack<int>();
	sccCnt = 0;
}

int DFS(int curr)
{
	dfsn[curr] = ++cnt;
	int result = dfsn[curr];
	S.push(curr);

	for (auto next : adjList[curr])
	{
		if (dfsn[next] == -1)
		{
			int dfsRet = DFS(next);
			result = min(result, dfsRet);
		}
		else // 역방향 / 순방향 / 교차
		{
			if (finished[next])
			{
				// pass
			}
			else
			{
				result = min(result, dfsn[next]);
			}
		}
	}

	if (result >= dfsn[curr])
	{
		vector<int> currSCC;
		while (true)
		{
			int t = S.top(); S.pop(); 
			finished[t] = true;
			sccn[t] = sccCnt;

			currSCC.push_back(t);
			
			if (t == curr)
				break;
		}
		SCC.push_back(currSCC);
		sccCnt++;
	}

	return result;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		Init();
		cin >> n;
		if (n == 0) break;
		cin >> m;

		adjList.resize(n + 1);

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			adjList[a].push_back(b);
		}

		for (int i = 1; i <= n; i++)
		{
			if (dfsn[i] == -1)
				DFS(i);
		}

		for (int from = 1; from <= n; from++)
		{
			for (auto to : adjList[from])
			{
				if (sccn[from] != sccn[to])
				{
					sccOutdegree[sccn[from]]++;
				}
			}
		}

		vector<int> ret;

		for (int i = 0; i < sccCnt; i++)
		{
			if (sccOutdegree[i] == 0)
			{
				for (auto item : SCC[i])
					ret.push_back(item);
			}
		}

		sort(ret.begin(), ret.end());
		for (auto item : ret)
			cout << item << " ";
		cout << endl;
	}
}
