#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> P;

struct Node
{
	Node(int row, int col, int dir, int cnt)
	{
		this->row = row;
		this->col = col;
		this->dir = dir;
		this->cnt = cnt;
	}

	int row, col, dir, cnt;
};

int dRow[4] = { 0, -1, 0, 1 }; // 우, 상, 좌, 하
int dCol[4] = { 1, 0, -1, 0 };

int W, H;
char grid[100][100];
int mirrorCount[100][100][4];
P startPoint;

int Test()
{
	int ret = INT_MAX;
	fill(&mirrorCount[0][0][0], &mirrorCount[99][99][4], 1000000);

	queue<Node> Q;

	for (int dir = 0; dir < 4; dir++)
	{
		mirrorCount[startPoint.first][startPoint.second][dir] = 0;
		Q.push(Node(startPoint.first, startPoint.second, dir, 0));
	}
	// 시작점의 'C'는 지워두기
	grid[startPoint.first][startPoint.second] = '*';

	while (!Q.empty())
	{
		Node curr = Q.front(); Q.pop();

		if (grid[curr.row][curr.col] == 'C') // 도착
		{
			ret = min(ret, curr.cnt);
			//cout << "도착, 거울 사용 횟수: " << curr.cnt << endl;
			continue;
		}
		
		if (grid[curr.row][curr.col] == '.') // 거울 설치 가능
		{
			// / 거울 설치
			int nDir;
			if (curr.dir == 0)
				nDir = 1;
			else if (curr.dir == 1)
				nDir = 0;
			else if (curr.dir == 2)
				nDir = 3;
			else if (curr.dir == 3)
				nDir = 2;

			int nRow = curr.row + dRow[nDir];
			int nCol = curr.col + dCol[nDir];

			bool isValid = true;
			if (nRow < 0 || nCol < 0 || nRow >= H || nCol >= W)
				isValid = false;
			if (grid[nRow][nCol] == '*')
				isValid = false;

			if (isValid && mirrorCount[nRow][nCol][nDir] > curr.cnt + 1)
			{
				mirrorCount[nRow][nCol][nDir] = curr.cnt + 1;
				Q.push(Node(nRow, nCol, nDir, curr.cnt + 1));
			}

			// \ 거울 설치
			nDir;
			if (curr.dir == 0)
				nDir = 3;
			else if (curr.dir == 1)
				nDir = 2;
			else if (curr.dir == 2)
				nDir = 1;
			else if (curr.dir == 3)
				nDir = 0;

			nRow = curr.row + dRow[nDir];
			nCol = curr.col + dCol[nDir];

			isValid = true;
			if (nRow < 0 || nCol < 0 || nRow >= H || nCol >= W)
				isValid = false;
			if (grid[nRow][nCol] == '*')
				isValid = false;

			if (isValid && mirrorCount[nRow][nCol][nDir] > curr.cnt + 1)
			{
				mirrorCount[nRow][nCol][nDir] = curr.cnt + 1;
				Q.push(Node(nRow, nCol, nDir, curr.cnt + 1));
			}
		}

		// 거울 설치 없이 가보기
		int nRow = curr.row + dRow[curr.dir];
		int nCol = curr.col + dCol[curr.dir];
		bool isValid = true;
		if (nRow < 0 || nCol < 0 || nRow >= H || nCol >= W)
			isValid = false;
		if (grid[nRow][nCol] == '*')
			isValid = false;

		if (isValid && mirrorCount[nRow][nCol][curr.dir] > curr.cnt)
		{
			mirrorCount[nRow][nCol][curr.dir] = curr.cnt;
			Q.push(Node(nRow, nCol, curr.dir, curr.cnt));
		}
	}

	return ret;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> W >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			char input;
			cin >> input;
			grid[i][j] = input;
			if (input == 'C')
				startPoint = P(i, j);
		}
	}

	cout << Test();
}
