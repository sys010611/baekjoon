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
	int dayOrNight;

	node(int row, int col, int brokeWalls, int dayOrNight)
	{
		this->row = row;
		this->col = col;
		this->brokeWalls = brokeWalls;
		this->dayOrNight = dayOrNight;
	}
};

char map[1000][1000];
bool visited[1000][1000][11][2];

int BFS(int startRow, int startCol)
{
	queue<node> Q; // 좌표, 부숨 여부

	Q.push(node(startRow, startCol, 0, 0));
	visited[startRow][startCol][0][0] = true;

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
			int currDayOrNight = curr.dayOrNight;

			if (currRow == n - 1 && currCol == m - 1)
			{
				return level;
			}

			int nDayOrNight = (currDayOrNight + 1) % 2;

			if (!visited[currRow][currCol][currBrokeWalls][nDayOrNight])
			{
				Q.push(node(currRow, currCol, currBrokeWalls, nDayOrNight));
				visited[currRow][currCol][currBrokeWalls][nDayOrNight] = true;
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
					if (map[nRow][nCol] == '1' && currDayOrNight == 0)
					{
						if (currBrokeWalls < k && !visited[nRow][nCol][currBrokeWalls + 1][nDayOrNight])
						{
							Q.push(node(nRow, nCol, currBrokeWalls + 1, nDayOrNight));
							visited[nRow][nCol][currBrokeWalls + 1][nDayOrNight] = true;
						}
					}
					else if (map[nRow][nCol] == '0' && !visited[nRow][nCol][currBrokeWalls][nDayOrNight])
					{
						Q.push(node(nRow, nCol, currBrokeWalls, nDayOrNight));
						visited[nRow][nCol][currBrokeWalls][nDayOrNight] = true;
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