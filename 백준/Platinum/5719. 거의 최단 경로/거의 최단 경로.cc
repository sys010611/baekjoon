#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
using namespace std;

typedef pair<int, int> P;
#define INF 1000000
#define SIZE 501

int dist[SIZE];
bool visited[SIZE];
vector<vector<P>> adjList;
int N, M, S, D;
vector<vector<int>> newGraph;

void FindShortestPath() // 다익스트라를 돌려서, 방문 경로를 바탕으로 새로운 그래프를 하나 만든다.
{
	fill(dist, dist + SIZE, INF);
	fill(visited, visited + SIZE, false);

	priority_queue<P, vector<P>, greater<P>> PQ;

	dist[S] = 0;
	PQ.push(P(0, S));
	while (!PQ.empty())
	{
		P curr = PQ.top(); PQ.pop();

		int currDist = curr.first;
		int currNode = curr.second;

		//cout << "currNode : " << currNode << endl;
		//cout << "currDist : " << currDist << endl;

		if (visited[currNode])
			continue;
		visited[currNode] = true;

		for (P& next : adjList[currNode])
		{
			int cost = next.first;
			int nextNode = next.second;

			if (!visited[nextNode] && dist[nextNode] > dist[currNode] + cost)
			{
				dist[nextNode] = dist[currNode] + cost;
				PQ.push(P(dist[nextNode], nextNode));

				newGraph[nextNode].clear();
				newGraph[nextNode].push_back(currNode);
			}
			else if (!visited[nextNode] && dist[nextNode] == dist[currNode] + cost)
			{
				newGraph[nextNode].push_back(currNode);
			}
		}
	}

	//cout << "new graph: " << endl;
	//for (int i = 0; i < N; i++)
	//{
	//	cout << i << " : ";
	//	for (auto next : newGraph[i])
	//		cout << next << " ";
	//	cout << endl;
	//}
}

// newGraph를 BFS로 돌며 간선들 제외하기
void RemoveEdges()
{
	fill(visited, visited + SIZE, false);

	queue<int> Q;
	Q.push(D);
	visited[D] = true;

	while (!Q.empty())
	{
		int curr = Q.front(); Q.pop();
		if (curr == S)
			continue;
		
		for (auto next : newGraph[curr]) //next -> curr로 가는 간선을 삭제해야 함
		{
			for (auto& adj : adjList[next])
			{
				int nodeNum = adj.second;
				if (nodeNum == curr)
				{
					adj.first = INF;
					//printf("%d -> %d 간선 삭제\n", next, curr);
					break;
				}
			}

			if (!visited[next])
			{
				visited[next] = true;
				Q.push(next);
			}
		}
	}
}

// 그냥 다익스트라 돌리기
void FindAlmostSP()
{
	fill(dist, dist + SIZE, INF);
	fill(visited, visited + SIZE, false);

	priority_queue<P, vector<P>, greater<P>> PQ;

	dist[S] = 0;
	PQ.push(P(0, S));
	while (!PQ.empty())
	{
		P curr = PQ.top(); PQ.pop();

		int currDist = curr.first;
		int currNode = curr.second;

		if (visited[currNode])
			continue;
		visited[currNode] = true;

		for (P& next : adjList[currNode])
		{
			int cost = next.first;
			int nextNode = next.second;

			if (!visited[nextNode] && dist[nextNode] > dist[currNode] + cost)
			{
				dist[nextNode] = dist[currNode] + cost;
				PQ.push(P(dist[nextNode], nextNode));
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true)
	{
		adjList.clear();
		fill(dist, dist + SIZE, INF);
		fill(visited, visited + SIZE, false);

		cin >> N >> M;

		if (N == 0 && M == 0)
			return 0;

		cin >> S >> D;
		adjList.resize(N);
		newGraph.resize(N);

		for (int i = 0; i < M; i++)
		{
			int u, v, p;
			cin >> u >> v >> p;
			adjList[u].push_back(P(p, v));
		}


		FindShortestPath();

		RemoveEdges();

		FindAlmostSP();

		int ret = dist[D];

		if(ret == INF)
			cout << -1 << '\n';
		else
			cout << dist[D] << '\n';

	}
		
}
