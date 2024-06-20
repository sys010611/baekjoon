#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k;

int dRow[4] = { 0, -1, 0, 1 };
int dCol[4] = { 1, 0, -1, 0 };

struct node
{
	int row, col;
	int brokeWalls;

	node(int row, int col, int brokeWalls)
	{
		this->row = row;
		this->col = col;
		this->brokeWalls = brokeWalls;
	}
};

char map[1000][1000];
bool visited[1000][1000][11];

int BFS(int startRow, int startCol)
{
	queue<node> Q; // 좌표, 부숨 여부

	Q.push(node(startRow, startCol, 0));
	visited[startRow][startCol][0] = true;

	int level = 1;
	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			node curr = Q.front(); Q.pop();

			int currRow = curr.row;
			int currCol = curr.col;
			int currBrokeWalls = curr.brokeWalls;

			if (currRow == n - 1 && currCol == m - 1)
			{
				return level;
			}

			for (int i = 0; i < 4; i++)
			{
				int nRow = currRow + dRow[i];
				int nCol = currCol + dCol[i];

				if (nRow < 0 || nCol < 0 || nRow >= n || nCol >= m)
				{
					continue;
				}
				else
				{
					if (map[nRow][nCol] == '1')
					{
						if (currBrokeWalls < k && !visited[nRow][nCol][currBrokeWalls+1])
						{
							Q.push(node(nRow, nCol, currBrokeWalls+1));
							visited[nRow][nCol][currBrokeWalls+1] = true;
						}
					}
					else if (map[nRow][nCol] == '0' && !visited[nRow][nCol][currBrokeWalls])
					{
						Q.push(node(nRow, nCol, currBrokeWalls));
						visited[nRow][nCol][currBrokeWalls] = true;
					}
				}
			}
		}
		level++;
	}

	return -1;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	cout << BFS(0, 0);
}