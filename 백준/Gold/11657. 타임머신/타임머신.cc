#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define int long long
typedef pair<int,int> P;
const int INF = INT_MAX;

int N, M;
vector<vector<P>> adjList;
int dist[501];

signed main()
{
	cin >> N >> M;

	fill(dist, dist+501, INF);
	dist[1] = 0;

	adjList.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		adjList[A].push_back(P(B, C));
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (auto adjNode : adjList[j])
			{
				if (dist[j] != INF)
				{
					if (dist[adjNode.first] > dist[j] + adjNode.second)
					{
						dist[adjNode.first] = dist[j] + adjNode.second;
						
						if (i == N - 1)
						{
							cout << -1;
							return 0;
						}
					}
				}
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (dist[i] == INF)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << dist[i] << endl;
		}
	}
}
