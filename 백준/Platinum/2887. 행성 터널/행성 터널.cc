#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

struct pos
{
	int x, y, z, index;
};

bool compareX(pos& a, pos& b)
{
	return a.x < b.x;
}
bool compareY(pos& a, pos& b)
{
	return a.y < b.y;
}
bool compareZ(pos& a, pos& b)
{
	return a.z < b.z;
}

int N;
vector<pos> positions;
vector<vector<P>> adjList; // <거리, 노드번호>

long long Prim()
{
	long long result = 0;

	priority_queue<P, vector<P>, greater<P>> PQ;
	
	vector<bool> visited;
	visited.resize(N);
	fill(visited.begin(), visited.end(), false);

	PQ.push(P(0, 0));
	while (!PQ.empty())
	{
		P curr = PQ.top(); PQ.pop();

		int currDist = curr.first;
		int currNode = curr.second;

		if (visited[currNode])
			continue;

		visited[currNode] = true;
		result += currDist;

		for (P next : adjList[currNode])
		{
			int nextDist = next.first;
			int nextNode = next.second;

			if (!visited[nextNode])
			{
				PQ.push(P(nextDist, nextNode));
			}
		}
	}

	return result;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	positions.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> positions[i].x >> positions[i].y >> positions[i].z;
		positions[i].index = i;
	}

	adjList.resize(N);

	// 각 축에 대하여 정렬 후, 인접 점들끼리 차를 구해서 그것만으로 adjList를 구축한다.
	// MST에는 N-1개의 점만 필요하므로, 각 축마다 구해진 N-1개의 cost 외는 MST의 간선으로 쓰여질 일이 없다.
	sort(positions.begin(), positions.end(), compareX);
	for (int i = 0; i < positions.size() - 1; i++)
	{
		int cost = abs(positions[i + 1].x - positions[i].x);
		
		int u = positions[i].index;
		int v = positions[i + 1].index;
		adjList[u].push_back(P(cost, v));
		adjList[v].push_back(P(cost, u));
	}

	sort(positions.begin(), positions.end(), compareY);
	for (int i = 0; i < positions.size() - 1; i++)
	{
		int cost = abs(positions[i + 1].y - positions[i].y);
		
		int u = positions[i].index;
		int v = positions[i + 1].index;
		adjList[u].push_back(P(cost, v));
		adjList[v].push_back(P(cost, u));
	}

	sort(positions.begin(), positions.end(), compareZ);
	for (int i = 0; i < positions.size() - 1; i++)
	{
		int cost = abs(positions[i + 1].z - positions[i].z);
		
		int u = positions[i].index;
		int v = positions[i + 1].index;
		adjList[u].push_back(P(cost, v));
		adjList[v].push_back(P(cost, u));
	}

	//for (int i = 0; i < N; i++)
	//{
	//	cout << i << " -> ";
	//	for (auto item : adjList[i])
	//	{
	//		printf("(%d, %d) ", item.first, item.second);
	//	}
	//	cout << endl;
	//}

	// 이제 Prim을 돌리면 끝
	cout << Prim();
}

