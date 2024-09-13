#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
char grid[50][50];
bool visited[50][50];

int dRow[4] = {0, -1, 0, 1};
int dCol[4] = {1, 0, -1, 0};

// 사이클 발견 시 true 리턴
bool dfs(int row, int col, int lastDir)
{
	//cout << "row : " << row << ", col : " << col << endl;
	visited[row][col] = true;

	for (int i = 0; i < 4; i++)
	{		
		int nRow = row + dRow[i];
		int nCol = col + dCol[i];

		if(nRow < 0 || nRow >= N || nCol < 0 || nCol >= M)
			continue;

		if (grid[row][col] != grid[nRow][nCol])
			continue;

		if (visited[nRow][nCol])
		{
			if (lastDir != -1 && i != (lastDir + 2) % 4)
			{
				//cout << "nRow : " << nRow << ", nCol : " << nCol << endl;
				//cout << "사이클 발견" << endl;
				return true;
			}
		}
		else
		{
			if(dfs(nRow, nCol, i))
				return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=0;i<50;i++)
		for(int j=0;j<50;j++)
			visited[i][j] = false;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visited[i][j])
			{
				//cout << grid[i][j] << "탐색 " << endl;
				if (dfs(i, j, -1))
				{
					cout << "Yes";
					return 0;
				}
			}
		}
	}
	cout << "No";
}