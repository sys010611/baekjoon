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

	fill(dfsn, dfsn + MAX, -1);
	fill(finished, finished + MAX, false);
	fill(isSccReachableFromStart, isSccReachableFromStart + MAX, false);
	fill(ret, ret + MAX, false);

	cin >> N >> M >> S >> T;
	adjList.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		adjList[A].push_back(B);
	}

	for (int i = 1; i <= N; i++)
	{
		if (dfsn[i] == -1)
			dfs(i);
	}

	//for (int i = 0; i < sccCnt; i++)
	//{
	//	cout << "scc " << i << " : ";
	//	for (auto item : SCC[i])
	//		cout << item << " ";
	//	cout << endl;
	//}

	for (int from = 1; from <= N; from++)
	{
		for (int to : adjList[from])
		{
			if (sccn[from] != sccn[to])
			{
				sccAdjList[sccn[from]].push_back(sccn[to]);
				sccIndegree[sccn[to]]++;
			}
		}
	}

	queue<int> Q;
	for (int i = 0; i < sccCnt; i++)
	{
		if (sccIndegree[i] == 0)
		{
			Q.push(i);
		}
	}

	isSccReachableFromStart[startSCC] = true;

	while (!Q.empty())
	{
		int curr = Q.front(); Q.pop();
		ret[curr] += SCC[curr].size();
		
		for (auto next : sccAdjList[curr])
		{
			if (isSccReachableFromStart[curr])
			{ 
				// 단순 누적이 아닌 선택을 해야 함
				isSccReachableFromStart[next] = true;

				ret[next] = max(ret[next], ret[curr]);
			}

			sccIndegree[next]--;

			if (sccIndegree[next] == 0)
				Q.push(next);
		}

		//cout << "현재 SCC : " << curr << endl;
		//cout << "ret : " << ret[curr] << endl;
	}

	if (isSccReachableFromStart[endSCC])
		cout << ret[endSCC];
	else
		cout << 0;
}
