#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;

int M, N;
int grid[101][101];
bool visited[101][101][4];

// 우, 상, 좌, 하
int dRow[4] = { 0, -1, 0, 1 };
int dCol[4] = { 1, 0, -1, 0 };

int sRow, sCol, sDir, eRow, eCol, eDir;

struct node
{
	node() = default;
	node(int row, int col, int dir)
	{
		r = row;
		c = col;
		d = dir;
	}

	bool operator==(node& ref)
	{
		return (r == ref.r) && (c == ref.c) && (d == ref.d);
	}

	int r, c, d;
};

node endNode;

int bfs()
{
	queue<node> Q;
	Q.push(node(sRow, sCol, sDir));

	int level = 0;
	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			node curr = Q.front(); Q.pop();

			//printf("curr : (%d, %d), %d\n", curr.r, curr.c, curr.d);

			if (curr == endNode)
			{
				//cout << "BFS  종료" << endl;
				return level;
			}
				

			// 방향 전환
			int nDir;
			nDir = (curr.d + 4 + 1) % 4;
			if (!visited[curr.r][curr.c][nDir])
			{
				visited[curr.r][curr.c][nDir] = true;
				Q.push(node(curr.r, curr.c, nDir));
			}
			nDir = (curr.d + 4 - 1) % 4;
			if (!visited[curr.r][curr.c][nDir])
			{
				visited[curr.r][curr.c][nDir] = true;
				Q.push(node(curr.r, curr.c, nDir));
			}

			// 이동
			int nRow, nCol;
			for (int i = 1; i <= 3; i++)
			{
				int nRow = curr.r + dRow[curr.d] * i;
				int nCol = curr.c + dCol[curr.d] * i;

				if (nRow < 1 || nRow > M || nCol < 1 || nCol > N)
					break;

				if (grid[nRow][nCol] == 1)
					break;

				if (!visited[nRow][nCol][curr.d])
				{
					visited[nRow][nCol][curr.d] = true;
					Q.push(node(nRow, nCol, curr.d));
				}
			}
		}
		level++;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(visited, 0, sizeof(visited));

	cin >> M >> N;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> grid[i][j];
		}
	}

	cin >> sRow >> sCol >> sDir;
	cin >> eRow >> eCol >> eDir;

	if (sDir == 1)
		sDir = 0;
	else if (sDir == 2)
		sDir = 2;
	else if (sDir == 3)
		sDir = 3;
	else if (sDir == 4)
		sDir = 1;

	if (eDir == 1)
		eDir = 0;
	else if (eDir == 2)
		eDir = 2;
	else if (eDir == 3)
		eDir = 3;
	else if (eDir == 4)
		eDir = 1;


	endNode = node(eRow, eCol, eDir);

	cout << bfs();
}
