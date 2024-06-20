#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;

int dRow[4] = {0, -1, 0, 1};
int dCol[4] = {1, 0, -1, 0};

struct node
{
	int row, col;
	int brokeWall;

	node(int row, int col, int brokeWall)
	{
		this->row = row;
		this->col = col;
		this->brokeWall = brokeWall;
	}
};

char map[1000][1000];
bool visited[1000][1000][2];

int BFS(int startRow, int startCol)
{
	queue<node> Q; // 좌표, 부숨 여부

	visited[startRow][startCol][false] = true;
	Q.push(node(startRow, startCol, false));


	int level = 1;
	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			node curr = Q.front(); Q.pop();

			int currRow = curr.row;
			int currCol = curr.col;
			bool currBrokeWall = curr.brokeWall;

			//printf("현재 방문 좌표 : %d, %d (%d)\n", currRow, currCol, currBrokeWall);
			//cout << "현재 level : " << level << endl;
			
			if (currRow == n - 1 && currCol == m - 1)
			{
				//cout << "도착 level : " << level << endl;
				return level;
			}

			for (int i = 0; i < 4; i++)
			{
				int nRow = currRow + dRow[i];
				int nCol = currCol + dCol[i];

				if (nRow < 0 || nCol < 0 || nRow >= n || nCol >= m || visited[nRow][nCol][currBrokeWall])
				{
					continue;
				}
				else
				{
					if (map[nRow][nCol] == '1')
					{
						if (currBrokeWall == false)
						{
							Q.push(node(nRow, nCol, true));
							visited[nRow][nCol][true] = true;
						}
					}
					else if (map[nRow][nCol] == '0')
					{
						Q.push(node(nRow, nCol, currBrokeWall));
						visited[nRow][nCol][currBrokeWall] = true;
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
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	cout << BFS(0,0);
}