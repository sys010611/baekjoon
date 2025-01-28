#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

int dRow[4] = {0, -1, 0, 1};
int dCol[4] = {1, 0, -1, 0};

int N;
int grid[100][100];
bool visited[100][100];
int result = -1;

void DFS(int row, int col, int height)
{
	if (visited[row][col])
	{
		return;
	}
	visited[row][col] = true;

	for (int i = 0; i < 4; i++)
	{
		int nRow = row + dRow[i];
		int nCol = col + dCol[i];

		if(nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
			continue;

		if(visited[nRow][nCol] || grid[nRow][nCol] <= height)
			continue;

		DFS(nRow, nCol, height);
	}
}

void Check(int height)
{
	//cout << "height : " << height << endl;

	memset(visited, 0, sizeof(visited));

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j] > height && !visited[i][j])
			{
				count++;
				DFS(i, j, height);
			}
		}
	}

	//cout << "결과 : " << count << endl;

	result = max(result, count);
}

signed main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> grid[i][j];
		}
	}

	for (int height = 0; height <= 100; height++)
	{
		Check(height);
	}

	cout << result;
}
