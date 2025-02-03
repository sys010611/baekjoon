#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int v, e;
int dfsn[100001]; // 방문 시간
int cnt = 0;
vector<vector<int>> adjList;
vector<P> resultLines;

// dfsn을 매겨주기
int dfs(int curr, int prev)
{
	dfsn[curr] = ++cnt;
	int result = dfsn[curr]; // 나와 내 자식들이 갈 수 있는 최소 dfsn

	for (auto next : adjList[curr])
	{
		if (next == prev) // 부모로 가는 간선은 패스
			continue;

		if (dfsn[next] == -1) // 미방문 (트리 간선)
		{
			int low = dfs(next, curr);

			if (low > dfsn[curr])
			{
				resultLines.push_back(P(min(curr, next), max(curr, next)));
			}

			result = min(result, low);
		}
		else // 역방향 간선
		{
			result = min(result, dfsn[next]);
		}
	}

	return result;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dfsn, -1, sizeof(dfsn));

	cin >> v >> e;
	adjList.resize(v + 1);

	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	dfs(1, 0);

	//for (int i = 1; i <= v; i++)
	//	cout << dfsn[i] << " ";
	//cout << endl;

	sort(resultLines.begin(), resultLines.end());
	cout << resultLines.size() << '\n';

	for (auto item : resultLines)
	{
		cout << item.first << " " << item.second << '\n';
	}
}
