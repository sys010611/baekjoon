#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <climits>
using namespace std;

#define int long long

typedef pair<int, int> P;
#define INF 1e11
#define MAX 100001

int N, M;
vector<vector<P>> adjList; // <time, next>
int dist[MAX];
bool visited[MAX];

void dijkstra()
{
	dist[1] = 0;
	
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, 1));

	while (!PQ.empty())
	{
		P curr = PQ.top(); PQ.pop();
		int currNode = curr.second;
		//cout << "currNode : " << currNode << endl;

		if (visited[currNode])
			continue;
		visited[currNode] = true;

		for (auto next : adjList[currNode])
		{
			int cost = next.first;
			int nextNode = next.second;

			if (visited[nextNode])
				continue;

			if (dist[currNode] >= cost)
			{
				int extraCycleCount = (dist[currNode] - cost + 1) / M;
				if ((dist[currNode] - cost + 1) % M != 0)
					extraCycleCount++;
				cost += M * extraCycleCount;
			}

			//while (!(dist[currNode] < cost))
			//{
			//	cost += M;
			//}

			if (dist[nextNode] > cost)
			{
				dist[nextNode] = cost;
				PQ.push(P(cost, nextNode));
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	fill(dist, dist + MAX, INF);
	fill(visited, visited + MAX, false);

	cin >> N >> M;

	adjList.resize(N + 1);

	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(P(i, b));
		adjList[b].push_back(P(i, a));
	}

	dijkstra();

	cout << dist[N];
}
