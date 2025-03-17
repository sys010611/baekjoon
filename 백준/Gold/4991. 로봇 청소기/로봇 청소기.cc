#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <climits>
#include <cmath>
#include <stack>
using namespace std;

int dRow[4] = { 0, -1, 0, 1 };
int dCol[4] = { 1, 0, -1, 0 };

typedef pair<int, int> P;
char grid[20][20];
bool visited[20][20][1 << 10];
P startPos;
int w, h;
int dirtyZoneCnt;

struct Node
{
	Node(int row, int col, int visited)
	{
		r = row;
		c = col;
		v = visited;
	}
	int r, c, v;
};

int BFS()
{
	queue<Node> Q;
	Q.push(Node(startPos.first, startPos.second, 0));

	int ret = 1000000;
	int level = 0;
	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			Node curr = Q.front();
			Q.pop();

			// 현재 방문한 칸이 더러운 칸일 경우
			if (0 <= grid[curr.r][curr.c] && grid[curr.r][curr.c] <= 9)
			{
				int bitNo = grid[curr.r][curr.c];
				if ((curr.v & (1 << bitNo)) == 0) // 아직 청소되어있지 않음
				{
					// 청소 (해당 비트 1로 변경)
					curr.v = curr.v | (1 << bitNo);

					//cout << "청소 후: " << bitset<10>(curr.v) << endl;
					//cout << "목표: " << bitset<10>((1 << dirtyZoneCnt) - 1) << endl;

					// 만약 모두 청소되었다면 현재 레벨 ret에 저장
					if (curr.v == (1 << dirtyZoneCnt) - 1)
					{
						//cout << "모두 청소 완료" << endl;
						ret = min(ret, level);
						continue;
					}
				}
			}

			for (int i = 0; i < 4; i++)
			{
				int nRow = curr.r + dRow[i];
				int nCol = curr.c + dCol[i];

				if (nRow < 0 || nCol < 0 || nRow >= h || nCol >= w)
				{
					continue;
				}
				if (grid[nRow][nCol] == 'x' || visited[nRow][nCol][curr.v])
				{
					continue;
				}

				visited[nRow][nCol][curr.v] = true;
				Q.push(Node(nRow, nCol, curr.v));
			}
		}
		level++;
	}

	if (ret == 1000000)
		return -1;
	else
		return ret;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			return 0;

		dirtyZoneCnt = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				char input;
				cin >> input;
				grid[i][j] = input;

				if (input == 'o')
				{
					startPos = P(i, j);
				}
				else if (input == '*')
				{
					grid[i][j] = dirtyZoneCnt;
					dirtyZoneCnt++;
				}

			}
		}

		memset(visited, 0, sizeof(visited));
		cout << BFS() << endl;
	}
}
