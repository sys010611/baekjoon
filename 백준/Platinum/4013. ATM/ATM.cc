#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define MAX 500001

int N, M;
vector<int> adjList[MAX];
int money[MAX];
int dfsn[MAX];
int finished[MAX];
int sccn[MAX];
int hasRest[MAX];
vector<int> sccAdjList[MAX];
int sccIndegree[MAX];
int sccMoney[MAX];
int sccMaxMoney[MAX];
bool sccHasRest[MAX];
bool sccCanReachFromStart[MAX] = { 0, };
int cnt = 0;
int S, P;
stack<int> st;
vector<vector<int>> SCC;
int sccIdx = -1;

int DFS(int curr)
{
	dfsn[curr] = ++cnt;
	int result = dfsn[curr];
	st.push(curr);

	for (auto next : adjList[curr])
	{
		if (dfsn[next] == -1)
		{
			result = min(result, DFS(next));
		}
		else
		{
			if (!finished[next])
			{
				result = min(result, dfsn[next]);
			}
		}
	}

	//SCC 발견
	if (result >= dfsn[curr])
	{
		sccIdx++;
		vector<int> currSCC;
		while (true)
		{
			int top = st.top(); st.pop();
			finished[top] = true;
			sccn[top] = sccIdx;
			sccMoney[sccIdx] += money[top];
			if (hasRest[top])
				sccHasRest[sccIdx] = true;

			currSCC.push_back(top);

			if (top == curr)
				break;
		}
		SCC.push_back(currSCC);
	}

	return result;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dfsn, -1, sizeof(dfsn));
	memset(finished, 0, sizeof(finished));
	memset(money, 0, sizeof(money));
	memset(sccMoney, 0, sizeof(sccMoney));
	memset(hasRest, 0, sizeof(hasRest));
	memset(sccHasRest, 0, sizeof(sccHasRest));
	memset(sccIndegree, 0, sizeof(sccIndegree));
	memset(sccMaxMoney, 0, sizeof(sccMaxMoney));

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
	}

	for (int i = 1; i <= N; i++)
	{
		cin >> money[i];
	}

	cin >> S >> P;
	for (int i = 0; i < P; i++)
	{
		int nodeNo; cin >> nodeNo;
		hasRest[nodeNo] = true;
	}
	//cout << "INPUT DONE" << endl;

	for (int i = 1; i <= N; i++)
	{
		if (dfsn[i] == -1)
			DFS(i); // SCC 구하기
	}

	//cout << "SCC : " << endl;
	//for (auto currSCC : SCC)
	//{
	//	for (auto item : currSCC)
	//		cout << item << " ";
	//	cout << endl;
	//}
	//cout << endl;

	// SCC간 연결그래프 만들기
	for (int from = 1; from <= N; from++)
	{
		for (auto to : adjList[from])
		{
			if (sccn[from] != sccn[to])
			{
				int scc1 = sccn[from];
				int scc2 = sccn[to];
				if (find(sccAdjList[scc1].begin(), sccAdjList[scc1].end(), scc2) == sccAdjList[scc1].end())
				{
					sccAdjList[scc1].push_back(scc2);
					sccIndegree[scc2]++;
				}
			}
		}
	}

	//cout << "SCC ADJ LIST: " << endl;
	//for (int i = 0; i <= sccIdx; i++)
	//{
	//	cout << i << " -> ";
	//	for (auto next : sccAdjList[i])
	//	{
	//		cout << next << " ";
	//	}
	//	cout << endl;
	//}

	// SCC 단위로 위상정렬
	queue<int> Q;
	for (int i = 0; i <= sccIdx; i++)
	{
		if (i == sccn[S])
			sccCanReachFromStart[i] = true;

		if (sccIndegree[i] == 0)
		{
			Q.push(i);
		}
	}
	while (!Q.empty())
	{
		int curr = Q.front(); Q.pop();

		sccMaxMoney[curr] += sccMoney[curr];
		//cout << curr << "번 SCC 최대 수익 : " << sccMaxMoney[curr] << endl;

		for (auto next : sccAdjList[curr])
		{
			if (sccCanReachFromStart[curr])
			{
				sccMaxMoney[next] = max(sccMaxMoney[next], sccMaxMoney[curr]);
				sccCanReachFromStart[next] = true;
			}

			sccIndegree[next]--;
			if (sccIndegree[next] == 0)
			{
				Q.push(next);
			}
		}
	}

	int ret = 0;
	for (int i = 0; i <= sccIdx; i++)
	{
		if (sccHasRest[i] && sccCanReachFromStart[i])
		{
			ret = max(ret, sccMaxMoney[i]);
		}
	}
	cout << ret;

	return 0;
}
