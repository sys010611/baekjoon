#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dy[] = {0,0,-1,1};
int dx[] = {1,-1,0,0};

int map[1000][1000];
bool visited[1000][1000];
int n, m;

bool inRange(int col, int row)
{
	if(col < 0 || col >= n)
		return false;
	if(row < 0 || row >= m)
		return false;
	return true;
}

void bfs(int startCol, int startRow)
{
	int distance = 1;
	visited[startCol][startRow] = true;
	map[startCol][startRow] = 0;
	queue<pair<int,int>> Q;

	Q.push({startCol, startRow});
	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			int currCol = Q.front().first;
			int currRow = Q.front().second;
			Q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextCol = currCol+dy[i];
				int nextRow = currRow+dx[i];
				if (inRange(nextCol, nextRow) && !visited[nextCol][nextRow] && map[nextCol][nextRow] != 0)
				{
					visited[nextCol][nextRow] = true;
					map[nextCol][nextRow] = distance;
					Q.push({nextCol,nextRow});
				}
			}
		}
		distance++;
	}
}

int main()
{
	for(int i=0;i<1000;i++)
		fill(visited[i], visited[i]+1000, false);

	cin >> n >> m;

	int destY, destX; //목표지점 좌표

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 2)
				destY = i, destX = j;
		}
	}

	bfs(destY, destX);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(!visited[i][j] && map[i][j] == 1)
				map[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}