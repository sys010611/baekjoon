#include <iostream>
#include <algorithm>
using namespace std;
#define INF 100000000

long long cost[101][101];

void costCheck(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(cost[i][j] == INF)
				cout << 0 << " ";
			else
				cout << cost[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 101; i++) //비용을 무한대로 초기화
	{
		for (int j = 0; j < 101; j++)
		{
			cost[i][j] = INF;
		}
	}

	int n,m;
	cin >> n >> m;

	int s,d,c;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> d >> c;
		if (c < cost[s][d])
		{
			cost[s][d] = c;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cost[i][i] = 0; //자기자신으로 가는 비용은 0
	}
	//costCheck(n);

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (cost[i][j] > cost[i][k] + cost[k][j])
				{
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}

	costCheck(n);
}