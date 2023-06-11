#include <iostream>
using namespace std;

int graph[101][101];
#define INF 100000000
int n, m;

void print()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	cin >> n >> m; //노드개수, 간선개수

	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			graph[i][j] = INF;
	for(int i=0;i<101;i++)
		graph[i][i] = 0;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	//print();

	//플로이드
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if(graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	//print();
	

	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			graph[i][1] += graph[i][j];
		}
	}

	//print();

	int minDist = 100000000;
	int result = -1;
	for (int i = 1; i <= n; i++)
	{
		if (minDist > graph[i][1])
		{
			minDist = graph[i][1];
			result = i;
		}
	}

	cout << result;
}