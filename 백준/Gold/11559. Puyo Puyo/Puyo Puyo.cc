#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <climits>
#include <cmath>
#include <stack>
using namespace std;

typedef pair<int, int> P; 
queue<P> Q; // 지울 블록들의 좌표들을 저장

int dRow[4] = { 0, -1, 0, 1 };
int dCol[4] = { 1, 0, -1, 0 };

char grid[12][6];
bool visited[12][6];

void DFS(int row, int col, int color)
{
	Q.push(P(row, col));
	visited[row][col] = true;

	for (int i = 0; i < 4; i++)
	{
		int nRow = row + dRow[i];
		int nCol = col + dCol[i];

		if (nRow < 0 || nCol < 0 || nRow >= 12 || nCol >= 6 || visited[nRow][nCol])
		{
			continue;
		}
		if (grid[nRow][nCol] == color)
		{
			DFS(nRow, nCol, color);
		}
	}
}

bool RemoveBlocks()
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			visited[i][j] = false;

	bool ret = false;

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (grid[i][j] != '.' && !visited[i][j])
			{
				Q = queue<P>();
				DFS(i, j, grid[i][j]);
				if (Q.size() >= 4)
				{
					ret = true;
					while (!Q.empty())
					{
						P pos = Q.front(); 
						Q.pop();

						grid[pos.first][pos.second] = '.';
					}
				}
			}
		}
	}

	return ret;
}

void LowerBlocks()
{
	for (int col = 0; col < 6; col++) // 각 열에 대해서 반복
	{
		for (int i = 0; i < 12; i++) // 최대 12번 떨구기
		{
			for (int row = 11; row >= 1; row--)
			{
				if (grid[row][col] == '.' && grid[row - 1][col] != '.') // 나는 비어있는데, 내 위가 비어있지 않다면
				{
					grid[row][col] = grid[row - 1][col];
					grid[row - 1][col] = '.';
				}
			}
		}
	}
}

void PrintGrid()
{
	cout << endl;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << grid[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> grid[i][j];
		}
	}

	//RemoveBlocks();
	//PrintGrid();

	//LowerBlocks();
	//PrintGrid();

	for (int t = 0;; t++)
	{
		//cout << "t : " << t << endl;
		if (!RemoveBlocks())
		{
			cout << t;
			return 0;
		}

		//PrintGrid();

		LowerBlocks();

		//PrintGrid();
	}
}
