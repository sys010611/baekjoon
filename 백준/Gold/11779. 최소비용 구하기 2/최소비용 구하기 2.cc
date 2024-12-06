#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

#define SIZE 1001
#define INF INT_MAX

typedef pair<int, int> P;

int n, m;
vector<vector<P>> adjList; // <거리, 노드번호>
int prevNode[SIZE];
int visited[SIZE];
int dist[SIZE];

void dijkstra(int s, int e)
{
	priority_queue<P, vector<P>, greater<P>> PQ;
	stack<int> S;

	dist[s] = 0;
	PQ.push(P(0, s));

	while (!PQ.empty())
	{
		P curr = PQ.top(); PQ.pop();

		int currNode = curr.second;
		int currDist = curr.first;

		if (visited[currNode])
			continue;

		visited[currNode] = true;

		for (P& next : adjList[currNode])
		{
			int cost = next.first;

			int nextNode = next.second;
			int nextDist = dist[currNode] + cost;
			if (!visited[nextNode] && nextDist < dist[nextNode])
			{
				prevNode[nextNode] = currNode;
				dist[nextNode] = nextDist;
				PQ.push(P(nextDist, nextNode));
			}
		}
	}

	cout << dist[e] << endl;

	int p = e;
	do
	{
		S.push(p);
		p = prevNode[p];
	}
	while (p != -1);

	cout << S.size() << endl;
	while (!S.empty())
	{
		cout << S.top() << " "; S.pop();
	}
}

signed main()
{
	memset(prevNode, -1, sizeof(prevNode));
	memset(visited, 0, sizeof(visited));
	fill(dist, dist + SIZE, INF);

	cin >> n >> m;

	adjList.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adjList[a].push_back(P(c, b));
	}

	int s, e;
	cin >> s >> e;

	dijkstra(s, e);
}
