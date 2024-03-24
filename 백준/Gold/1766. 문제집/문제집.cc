#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, M;

vector<int> indegree;
vector<vector<int>> adjList;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	indegree.resize(N+1);
	adjList.resize(N+1);

	fill(indegree.begin(), indegree.end(), 0);

	int a,b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		indegree[b]++;
		adjList[a].push_back(b);
	}

	//for (int i = 1; i <= N; i++)
	//	cout << i << " node indegree: " << indegree[i] << endl;

	priority_queue<int, vector<int>, greater<int>> Q;
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			Q.push(i);
		}
	}
	while (!Q.empty())
	{
		int curr = Q.top(); Q.pop();

		cout << curr << " ";

		for (auto next : adjList[curr])
		{
			indegree[next]--;
			if (indegree[next] == 0)
			{
				Q.push(next);
			}
		}
	}
}