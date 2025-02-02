#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int v, e;
int discovered[10001]; // 방문 시간
bool ret[10001];
int cnt = 0;
vector<vector<int>> adjList;

// dfsn을 매겨주기
int dfs(int curr, bool isRoot)
{
	discovered[curr] = ++cnt;
	int lowestNum = discovered[curr]; // 나와 내 자식들이 갈 수 있는 가장 작은 방문 순서 번호

	int childCount = 0;
	for (auto next : adjList[curr])
	{
		if (discovered[next] == -1) // 미방문
		{
			childCount++;
			int low = dfs(next, false);
			lowestNum = min(lowestNum, low);
			if (!isRoot && low >= discovered[curr])
			{
				ret[curr] = true;
			}
		}
		else
		{
			lowestNum = min(lowestNum, discovered[next]);
		}
	}

	if (isRoot && childCount >= 2)
		ret[curr] = true;

	//cout << "curr : " << curr << endl;
	//cout << "discovered[curr] : " << discovered[curr] << endl;
	//cout << "나와 내 자식들이 갈 수 있는 가장 작은 discovered: " << lowestNum << endl;

	return lowestNum;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(discovered, -1, sizeof(discovered));
	memset(ret, 0, sizeof(ret));

	cin >> v >> e;
	adjList.resize(v + 1);

	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	for(int i = 1;i<=v;i++)
		dfs(i, true);

	//for (int i = 1; i <= v; i++)
	//	cout << discovered[i] << " ";

	//cout << endl;

	//for (int i = 1; i <= v; i++)
	//	cout << ret[i] << " ";

	int retcnt = 0;
	for (int i = 1; i <= v; i++)
		if (ret[i])
			retcnt++;
	cout << retcnt << endl;

	for (int i = 1; i <= v; i++)
		if (ret[i])
			cout << i << " ";
}
