#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
using namespace std;

typedef pair<int,int> P;
const int INF = INT_MAX;

signed main()
{
	int t; cin >> t;
	while (t--)
	{
		int N, M, W;
		cin >> N >> M >> W;

		vector<vector<P>> adjList; // <노드 번호, 비용>
		adjList.resize(N+1);

		for (int i = 0; i < M; i++)
		{
			int s, e, cost;
			cin >> s >> e >> cost;
			adjList[s].push_back(P(e, cost));
			adjList[e].push_back(P(s, cost));
		}
		for (int i = 0; i < W; i++)
		{
			int s, e, cost;
			cin >> s >> e >> cost;
			adjList[s].push_back(P(e, -cost));
		}

		int dist[501];
		fill(dist, dist + 501, INF);

		bool minusCycleFound = false;

		for (int startNode = 1; startNode <= N; startNode++)
		{
			if(dist[startNode] != INF)
				continue;

			dist[startNode] = 0; 

			for (int i = 0; i < N; i++)
			{
				for (int curr = 1; curr <= N; curr++)
				{
					if (dist[curr] != INF)
					{
						for (auto next : adjList[curr])
						{
							int nodeNo = next.first;
							int cost = next.second;

							if (dist[nodeNo] > dist[curr] + cost)
							{
								if (i == N - 1)
								{
									minusCycleFound = true;
								}
								dist[nodeNo] = dist[curr] + cost;
								//cout << nodeNo << " dist update : " << dist[nodeNo] << endl;
							}
						}
					}
				}
			}
		}

		

		//for (int i = 1; i <= N; i++)
		//{
		//	cout << "dist to " << i << " : " << dist[i] << endl;
		//}
		if (minusCycleFound)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}
