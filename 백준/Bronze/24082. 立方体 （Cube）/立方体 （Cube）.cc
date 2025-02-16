#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define MAX 10001

int N, M, S, T;
vector<vector<int>> adjList;
int dfsn[MAX];
int cnt = 0;
bool finished[MAX];
stack<int> st;
vector<vector<int>> SCC;
vector<int> sccAdjList[MAX];
int sccn[MAX];
int sccIndegree[MAX];
int sccCnt = 0;
bool isSccReachableFromStart[MAX];
int ret[MAX]; // 각 SCC까지 가면서 방문 가능한 최대 노드 수
int startSCC;
int endSCC;

int dfs(int curr)
{
	dfsn[curr] = ++cnt;
	int result = dfsn[curr];
	st.push(curr);

	for (auto next : adjList[curr])
	{
		if (dfsn[next] == -1)
		{
			result = min(result, dfs(next));
		}
		else
		{
			if (!finished[next])
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
			int t = st.top(); st.pop();
			finished[t] = true;
			sccn[t] = sccCnt;

			if (t == S)
				startSCC = sccCnt;
			else if (t == T)
				endSCC = sccCnt;

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

	long long n;
	cin >> n;
	cout << n * n * n;
}
