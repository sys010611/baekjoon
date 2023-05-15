#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX_V = 20001; //최대 정점 개수
const int INF = 1000000000;
typedef pair<int,int> P;

vector<P> adjList[MAX_V]; //인접리스트 <거리, 노드번호>
bool visited[MAX_V]; //방문여부
int dist[MAX_V]; //노드 별 최단거리

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V,E,K; //노드개수, 간선개수, 시작노드
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		adjList[u].push_back(P(w,v));
	}

	fill(dist, dist+MAX_V, INF);
	priority_queue<P, vector<P>, greater<P>> PQ; // <거리, 노드번호>
	dist[K] = 0;
	PQ.push(P(dist[K], K));

	while (!PQ.empty())
	{
		int curr; //현재 정점
		do
		{
			curr = PQ.top().second;
			PQ.pop();
		}
		while(!PQ.empty() && visited[curr]);

		if(visited[curr])
			break;

		visited[curr] = true;

		for (auto& next : adjList[curr])
		{
			if(visited[next.second]) //이미 방문한 정점이면 스킵
				continue;

			int nextNode = next.second;
			int d = next.first; //현재 노드에서 인접한 노드까지의 거리
			if (dist[nextNode] > dist[curr] + d)
			{
				dist[nextNode] = dist[curr] + d;
				PQ.push(P(dist[nextNode], nextNode)); //최단거리가 갱신되었다면 PQ에 push
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if(dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}
}