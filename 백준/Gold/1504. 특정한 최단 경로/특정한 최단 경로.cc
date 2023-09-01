#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000000;
typedef pair<int, int> P;

int N, E;
bool visited[1000];
int dist[1000]; //N번 정점까지 가는 거리
vector<vector<P>> adjList; // 거리, 노드번호

P dijkstra(int start, int end1, int end2 = 0)
{
	//초기화작업
	fill(visited, visited + N + 1, false);
	for (int i = 0; i <= N; i++)
		dist[i] = INF;

	dist[start] = 0;

	priority_queue<P, vector<P>, greater<P>> pq; //거리, 노드번호
	pq.push({ 0, start });

	do
	{
		P curr = pq.top();
		pq.pop();

		int currNode = curr.second;
		int currDist = curr.first;

		if (visited[currNode]) continue;

		visited[currNode] = true;
		//cout << "currNode: " << currNode << endl;
		for (P& next : adjList[currNode])
		{
			if (dist[next.second] > dist[currNode] + next.first)
			{
				dist[next.second] = dist[currNode] + next.first;
				pq.push({ dist[next.second], next.second });
			}
		}
	} while (!pq.empty());

	/*cout << "시작점이 " << start << "일 때" << endl;
	cout << end1 << "까지의 거리: " << dist[end1] << endl;
	if (end2 != 0)
		cout << end2 << "까지의 거리: " << dist[end2] << endl;*/

	return {dist[end1], dist[end2]};
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> E;
	//cout << "vertex: " << N << " edge: " << E << endl;

	adjList.resize(N + 1);

	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		adjList[a].push_back({ c,b });
		adjList[b].push_back({ c,a });
	}

	/*for (int i = 1; i <= N; i++)
	{
		cout << "node " << i << endl;
		for (P adjNode : adjList[i])
		{
			cout << "adjNode: " << adjNode.first << " dist :" << adjNode.second << endl;
		}
	}*/

	int v1, v2;
	cin >> v1 >> v2;
	//cout << "거쳐야 할 정점: " << v1 << ", " << v2 << endl;

	P fromV1 = dijkstra(1, v1, v2);
	P fromN = dijkstra(N, v1, v2);
	P betweenV1V2 = dijkstra(v1,v2);

	if (fromV1.first >= INF && fromV1.second >= INF)
	{
		cout << -1; return 0;
	}
	if (fromN.first >= INF && fromN.second >= INF)
	{
		cout << -1; return 0;
	}
	if (betweenV1V2.first >= INF)
	{
		cout << -1; return 0;
	}
	
	int result1 = fromV1.first + fromN.second;
	int result2 = fromV1.second + fromN.first;
	int middleRoad = betweenV1V2.first;

	cout << min(result1, result2)+middleRoad;
}

