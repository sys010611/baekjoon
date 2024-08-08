#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define int long long

typedef pair<int,int> P;
#define INF 1000000000

int N, M;
vector<vector<P>> adjList;
vector<bool> visited;
int totalCost;

void Input()
{
	cin >> N >> M;
	adjList.resize(N);
	visited.resize(N);
	fill(visited.begin(), visited.end(), false);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		adjList[a].push_back({c, b});
		adjList[b].push_back({c, a});
		totalCost += c;
	}
}

int Prim()
{	
	int result = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;

	PQ.push({0, 0});

	while (!PQ.empty())
	{
		P curr = PQ.top(); PQ.pop();
		int currNode = curr.second;
		int currDist = curr.first;

		if(visited[currNode]) 
			continue;

		visited[currNode] = true;
		//cout << currNode << "로 연결, 비용 : " << currDist << endl;
		result += currDist;

		for (auto& adj : adjList[currNode])
		{
			int nextNode = adj.second;
			int cost = adj.first;

			if (!visited[nextNode])
			{
				PQ.push({cost, nextNode});
			}
		}
	}

	for(int i=0;i<N;i++)
		if(visited[i] == false)
			return -1;

	return result;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();

	int cost = Prim();
	if (cost == -1)
	{
		cout << -1;
		return 0;
	}
	cout << totalCost - cost;
}