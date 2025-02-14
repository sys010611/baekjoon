#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define MAX 100000

int N, M;
vector<vector<int>> adjList;
int dfsn[MAX];
int sccn[MAX];
int cnt;
bool finished[MAX];
stack<int> S;
vector<vector<int>> SCC;
int sccIndegree[MAX];
int sccIdx;

void Init()
{
	adjList = vector<vector<int>>();
	memset(dfsn, -1, sizeof(dfsn));
	memset(sccn, -1, sizeof(sccn));
	cnt = 0;
	memset(finished, 0, sizeof(finished));
	S = stack<int>();
	SCC = vector<vector<int>>();
	memset(sccIndegree, 0, sizeof(sccIndegree));
	sccIdx = 0;
}

int DFS(int curr)
{
	dfsn[curr] = ++cnt;
	int result = dfsn[curr];
	S.push(curr);

	//cout << "curr : " << curr << endl;
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

	//cout << "result : " << result << endl;
	if (result >= dfsn[curr])
	{
		vector<int> currSCC;
		while (true)
		{
			int t = S.top(); S.pop();
			currSCC.push_back(t);
			finished[t] = true;
			sccn[t] = sccIdx;
			if (t == curr)
				break;
		}
		SCC.push_back(currSCC);
		sccIdx++;
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
		Init();

		cin >> N >> M;
		adjList.resize(N);
		for (int i = 0; i < M; i++)
		{
			int A, B;
			cin >> A >> B;
			adjList[A].push_back(B);
		}

		for (int i = 0; i < N; i++)
		{
			if (dfsn[i] == -1)
			{
				DFS(i);
			}
		}

		//for (auto currSCC : SCC)
		//{
		//	for (auto item : currSCC)
		//		cout << item << " ";
		//	cout << endl;
		//}

		for (int i = 0; i < N; i++)
		{
			for (int j : adjList[i])
			{
				if (sccn[i] != sccn[j])
				{
					sccIndegree[sccn[j]]++;
				}
			}
		}



		vector<int> ret;

		int zeroIndegreeSccCnt = 0;
		for (int i = 0; i < sccIdx; i++)
		{
			if (sccIndegree[i] == 0)
			{
				zeroIndegreeSccCnt++;
				for (auto item : SCC[i])
					ret.push_back(item);
			}
		}

		if (zeroIndegreeSccCnt >= 2)
		{
			cout << "Confused" << endl;
		}
		else
		{
			sort(ret.begin(), ret.end());
			for (auto item : ret)
				cout << item << endl;
		}
		cout << endl;
	}
}
