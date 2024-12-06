#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

#define INF INT_MAX
#define SIZE 301
typedef pair<int, int> P;

int N;
int startingCost[SIZE];
bool visited[SIZE];
vector<vector<P>> adjList;

int Prim()
{
	int ret = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;

	for (int i = 0; i < N; i++)
	{
		PQ.push(P(startingCost[i], i));
	}

	while (!PQ.empty())
	{
		P curr = PQ.top(); PQ.pop();
		int currNode = curr.second;
		int currCost = curr.first;

		if (visited[currNode])
			continue;

		visited[currNode] = true;
		ret += currCost;

		for (P& next : adjList[currNode])
		{
			int nextCost = next.first;
			int nextNode = next.second;

			if (!visited[nextNode])
			{
				PQ.push(P(nextCost, nextNode));
			}
		}
	}
	return ret;
}

signed main()
{
	memset(visited, 0, sizeof(visited));

	cin >> N;
	adjList.resize(N + 1);
	for (int i = 0; i < N; i++)
	{
		cin >> startingCost[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int cost;
			cin >> cost;
			if (i == j)
				continue;
			adjList[i].push_back(P(cost, j));
		}
	}

	cout << Prim();
}
