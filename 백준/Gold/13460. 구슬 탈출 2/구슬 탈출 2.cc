#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dRow[4] = { 0, -1, 0, 1 };
int dCol[4] = { 1, 0, -1, 0 };

struct Info
{
	int rRow;
	int rCol;
	int bRow;
	int bCol;
	int depth;
};

int N, M;
char grid[11][11];
bool visited[11][11][11][11];

int BFS()
{
	Info start;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == 'R')
			{
				start.rRow = i; start.rCol = j;
			}
			else if (grid[i][j] == 'B')
			{
				start.bRow = i; start.bCol = j;
			}
		}
	}
	start.depth = 0;

	queue<Info> Q;
	visited[start.rRow][start.rCol][start.bRow][start.bCol] = true;
	Q.push(start);

	int ret = -1;

	while (!Q.empty())
	{
		Info curr = Q.front(); Q.pop();

		if (curr.depth > 10)
			continue;

		if (grid[curr.rRow][curr.rCol] == 'O' && grid[curr.bRow][curr.bCol] != 'O')
		{
			// 성공
			return curr.depth;
		}

		for (int dir = 0; dir < 4; dir++) // 4방향으로 굴려보기
		{
			int nextRRow = curr.rRow;
			int nextRCol = curr.rCol;
			int nextBRow = curr.bRow;
			int nextBCol = curr.bCol;

			int rMoveDist = 0;
			int bMoveDist = 0;
			while (true)
			{
				// 빨간 구슬 굴리기
				nextRRow += dRow[dir];
				nextRCol += dCol[dir];

				rMoveDist++;

				if (grid[nextRRow][nextRCol] == 'O')
					break;
				if (grid[nextRRow][nextRCol] == '#')
				{
					nextRRow -= dRow[dir];
					nextRCol -= dCol[dir];

					rMoveDist--;
					break;
				}
			}
			while (true)
			{
				// 파란 구슬 굴리기
				nextBRow += dRow[dir];
				nextBCol += dCol[dir];

				bMoveDist++;

				if (grid[nextBRow][nextBCol] == 'O')
					break;
				if (grid[nextBRow][nextBCol] == '#')
				{
					nextBRow -= dRow[dir];
					nextBCol -= dCol[dir];

					bMoveDist--;
					break;
				}
			}

			// 파란 구슬이 구멍에 빠진 경우 (실패)
			if (grid[nextBRow][nextBCol] == 'O')
			{
				continue;
			}

			// 구슬 겹침 예외처리
			if (nextRRow == nextBRow && nextRCol == nextBCol)
			{
				if (rMoveDist > bMoveDist)
				{
					nextRRow -= dRow[dir];
					nextRCol -= dCol[dir];
				}
				else
				{
					nextBRow -= dRow[dir];
					nextBCol -= dCol[dir];
				}
			}

			if (!visited[nextRRow][nextRCol][nextBRow][nextBCol])
			{
				visited[nextRRow][nextRCol][nextBRow][nextBCol] = true;
				Info next;
				next.rRow = nextRRow;
				next.rCol = nextRCol;
				next.bRow = nextBRow;
				next.bCol = nextBCol;
				next.depth = curr.depth + 1;
				Q.push(next);
			}
		}
	}

	return ret;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(visited, 0, sizeof(visited));

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
		}
	}

	cout << BFS();
}

