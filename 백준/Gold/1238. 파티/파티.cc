#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> P;
#define INF 100000000

int n, m, x;
vector<vector<P>> adjList;
vector<int> totalTime;

int Dijkstra(int start, int end)
{
	vector<bool> visited;
	visited.resize(n);
	fill(visited.begin(), visited.end(), false);

	vector<int> dist;
	dist.resize(n);
	fill(dist.begin(), dist.end(), INF);

	priority_queue<P, vector<P>, greater<P>> PQ;

	dist[start] = 0;
	PQ.push(P(dist[start], start));

	while (!PQ.empty())
	{
		int currNode = PQ.top().second;
		PQ.pop();

		if(visited[currNode])	
			continue;

		visited[currNode] = true;
		for (auto& next : adjList[currNode])
		{
			int nextNode = next.second;
			int cost = next.first;

			if (!visited[nextNode])
			{
				if (dist[nextNode] > dist[currNode] + cost)
				{
					dist[nextNode] = dist[currNode] + cost;
					PQ.push(P(dist[nextNode], nextNode));
				}
			}
		}
	}

	//cout << start+1 << " -> " << end+1 << " : " << dist[end] << endl;
	return dist[end];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> x;
	x--;

	adjList.resize(n);
	totalTime.resize(n);
	fill(totalTime.begin(), totalTime.end(), 0);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		adjList[a-1].push_back(P(c, b-1));
	}

	for (int i = 0; i < n; i++)
	{
		totalTime[i] += Dijkstra(i, x);
	}

	for (int i = 0; i < n; i++)
	{
		totalTime[i] += Dijkstra(x, i);
	}

	cout << *max_element(totalTime.begin(), totalTime.end());
}