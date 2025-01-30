#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> P;
typedef tuple<int, int, int> T;

int dRow[4] = {0, -1, 0, 1};
int dCol[4] = {1, 0, -1, 0};

int N;
char grid[50][50];
int mirrorCount[50][50][4];
P door1;

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

int Test()
{
	fill(&mirrorCount[0][0][0], &mirrorCount[49][49][4], 1000000);
	queue<Node> Q;

	mirrorCount[door1.first][door1.second][0] = 0;
	mirrorCount[door1.first][door1.second][1] = 0;
	mirrorCount[door1.first][door1.second][2] = 0;
	mirrorCount[door1.first][door1.second][3] = 0;
	Q.push(Node(door1.first, door1.second, 0, 0));
	Q.push(Node(door1.first, door1.second, 1, 0));
	Q.push(Node(door1.first, door1.second, 2, 0));
	Q.push(Node(door1.first, door1.second, 3, 0));

	int ret = INT_MAX;

	while (!Q.empty())
	{
		Node curr = Q.front(); Q.pop();
		int row = curr.row; 
		int col = curr.col;
		int dir = curr.dir;
		int cnt = curr.cnt;

		if (grid[row][col] == '#' && P(row, col) != door1)
		{
			ret = min(ret, cnt);
		}

		//printf("%d, %d\n", row, col);

		if (grid[row][col] == '!')
		{
			int nDir = -1;

			//cout << "거울 설치" << endl;

			// / 모양 거울 설치
			switch (dir)
			{
				case 0:
					nDir = 1;
					break;
				case 1:
					nDir = 0;
					break;
				case 2:
					nDir = 3;
					break;
				case 3:
					nDir = 2;
					break;
			}

			int nRow = row + dRow[nDir];
			int nCol = col + dCol[nDir];

			bool isValid = true;

			if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
				isValid = false;
			if (grid[nRow][nCol] == '*')
				isValid = false;


			if (isValid && mirrorCount[nRow][nCol][nDir] > cnt + 1)
			{
				mirrorCount[nRow][nCol][nDir] = cnt + 1;
				Q.push(Node(nRow, nCol, nDir, cnt + 1));
			}
			
			// \ 모양 거울 설치
			switch (dir)
			{
			case 0:
				nDir = 3;
				break;
			case 1:
				nDir = 2;
				break;
			case 2:
				nDir = 1;
				break;
			case 3:
				nDir = 0;
				break;
			}

			nRow = row + dRow[nDir];
			nCol = col + dCol[nDir];

			isValid = true;

			if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
				isValid = false;
			if (grid[nRow][nCol] == '*')
				isValid = false;


			if (isValid && mirrorCount[nRow][nCol][nDir] > cnt + 1)
			{
				mirrorCount[nRow][nCol][nDir] = cnt + 1;
				Q.push(Node(nRow, nCol, nDir, cnt + 1));
			}
		}

		// 그냥 진행
		int nRow = row + dRow[dir];
		int nCol = col + dCol[dir];

		bool isValid = true;
		if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
			isValid = false;
		if (grid[nRow][nCol] == '*')
			isValid = false;


		if (isValid && mirrorCount[nRow][nCol][dir] > cnt)
		{
			mirrorCount[nRow][nCol][dir] = cnt;
			Q.push(Node(nRow, nCol, dir, cnt));
		}
	}

	return ret;
}

signed main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char input; cin >> input;
			grid[i][j] = input;

			if(input == '#')
				door1 = P(i, j);
		}
	}

	cout << Test();
}
