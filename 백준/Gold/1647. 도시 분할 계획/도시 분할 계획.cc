#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int,int> P;
priority_queue<P, vector<P>, greater<P>> PQ;

int N, M;

class Graph
{
public:
	int N;
	vector<vector<P>> adjList;
	vector<bool> visited;

	Graph(int n)
	{
		N = n;
		adjList.resize(N);
		visited.resize(N);
		fill(visited.begin(), visited.end(), false);
	}

	void AddEdge(int u, int v, int cost)
	{
		adjList[u].push_back(P(cost, v));
		adjList[v].push_back(P(cost, u));
	}

	int Prim(int startNode)
	{
		int MST_cost = 0;
		int edgeCount = -1; // 첫 시작(실제로 간선을 넣지 않음)을 고려해서 -1로
		int edgeMaxCost = 0; 

		PQ.push(P(0, startNode));
		while (edgeCount < N-1)
		{
			P currNode = PQ.top(); PQ.pop();
			if(visited[currNode.second])
				continue;

			visited[currNode.second] = true;

			//cout << "포함된 노드 : " << currNode.second+1 << endl;
			//cout << "해당 경로 비용: " << currNode.first << endl;
			MST_cost += currNode.first;
			//cout << "현재 총 비용 : " << MST_cost << endl;
			edgeCount++;
			//cout << "현재 간선 개수: " << edgeCount << endl << endl;

			if(edgeMaxCost < currNode.first)
				edgeMaxCost = currNode.first;

			for (P& adjNode : adjList[currNode.second])
			{
				if (!visited[adjNode.second])
				{
					PQ.push(adjNode);
				}
			}
		}

		return MST_cost - edgeMaxCost;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;	

	Graph* G = new Graph(N);

	int a,b,c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;

		G->AddEdge(a-1,b-1,c);
	}

	cout << G->Prim(0);
}