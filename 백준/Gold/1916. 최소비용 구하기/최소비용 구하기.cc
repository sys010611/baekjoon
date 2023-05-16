#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 100000000;
const int MAX_V = 1001;

bool visited[MAX_V];
int cost[MAX_V];
vector<vector<pair<int,int>>> adjList; //각 노드의 인접리스트 <거리, 노드번호>

int main()
{
	fill(visited, visited+MAX_V, false);
	fill(cost, cost+MAX_V, INF);
	adjList.resize(MAX_V);

	int N, M; //노드개수, 간선개수
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int u,v,d;
		cin >> u >> v >> d; //시작노드, 도착노드, 비용
		adjList[u].push_back({d,v});
	}

	int start, destination; //출발도시, 도착 도시
	cin >> start >> destination;

	cost[start] = 0; //출발도시의 비용은 0
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ; //<비용, 노드번호>
	PQ.push({cost[start], start});

	//다익스트라
	while (!PQ.empty())
	{
		int curr;
		do
		{
			curr = PQ.top().second; PQ.pop();
		}
		while(!PQ.empty() && visited[curr]);

		if(visited[curr])
			break;

		visited[curr] = true;

		for (auto& next : adjList[curr])
		{
			int nextNode = next.second;
			int nextDis = next.first;
			if(visited[nextNode])
				continue;
			//현재 노드에서 가는 비용이 기존 비용보다 더 작다면 갱신
			if (cost[nextNode] > cost[curr] + nextDis)
			{
				cost[nextNode] = cost[curr] + nextDis;
				PQ.push({cost[nextNode], nextNode});
			}
		}
	}

	cout << cost[destination];
}


