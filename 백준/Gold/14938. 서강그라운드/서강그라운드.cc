#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

#define MAX 101
#define INF 10000000
typedef pair<int,int> P;

int n, m, r;
int itemCount[MAX];
bool visited[MAX];
int dist[MAX][MAX];

void floyd()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

void PrintDist()
{
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

signed main()
{
	fill(visited, visited+MAX, false);
	fill(&dist[0][0], &dist[MAX-1][MAX], INF);
	
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> itemCount[i];
	}

	for (int i = 0; i < r; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		dist[a][b] = l;
		dist[b][a] = l;
	}

	//PrintDist();

	floyd();

	//PrintDist();

	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if(dist[i][j] <= m)
				sum += itemCount[j];
		}
		ret = max(ret, sum);
	}
	cout << ret;
}
