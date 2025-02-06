#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> P;

#define MAX 100001

int N, M;
vector<vector<int>> adjList;
bool finished[MAX];
int dfsn[MAX];
int cnt;
int sccn[MAX]; // 각 노드가 몇번 scc에 속하는지
int sccIndegree[MAX]; // 각 SCC의 Indegree 개수
int sccCnt; // SCC 번호
stack<int> S;

int DFS(int curr)
{
	dfsn[curr] = ++cnt;
	int result = dfsn[curr];
	S.push(curr);

	for (auto next : adjList[curr])
	{
		if (dfsn[next] == -1)
		{
			result = min(result, DFS(next));
		}
		else // 역방향/순방향/교차
		{
			if (finished[next])
			{
				// do nothing
			}
			else
			{
				result = min(result, dfsn[next]);
			}
		}
	}

	// SCC 완성
	if (result >= dfsn[curr])
	{
		sccCnt++;
		while (true)
		{
			int t = S.top(); S.pop();
			finished[t] = true;
			sccn[t] = sccCnt;

			if (t == curr)
				break;
		}
	}

	return result;
}



signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		adjList = vector<vector<int>>();
		S = stack<int>();

		memset(dfsn, -1, sizeof(dfsn));
		memset(finished, 0, sizeof(finished));
		memset(sccn, -1, sizeof(sccn));
		memset(sccIndegree, 0, sizeof(sccIndegree));

		cnt = 0;
		sccCnt = 0;


		cin >> N >> M;
		adjList.resize(N + 1);

		for (int i = 0; i < M; i++)
		{
			int x, y; 
			cin >> x >> y;
			adjList[x].push_back(y);
		}

		// SCC 찾기
		for (int i = 1; i <= N; i++)
		{
			if (dfsn[i] == -1)
				DFS(i);
		}

		// SCC의 indegree 세기
		for (int from = 1; from <= N; from++)
		{
			for (int to : adjList[from])
			{
				if (sccn[from] != sccn[to])
				{
					sccIndegree[sccn[to]]++;
				}
			}
		}

		//cout << "SCC 개수 : " << sccCnt << endl;

		int ret = 0;

		for (int i = 1; i <= sccCnt; i++)
		{
			if (sccIndegree[i] == 0)
				ret++;
		}

		cout << ret << endl;
	}
}
