#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

int dRow[4] = {0, -1, 0, 1};
int dCol[4] = {1, 0, -1, 0};

int N, M;
int grid[8][8];
int result = 100000000;
vector<P> cams;

bool isInRange(int row, int col)
{
	if(row<0 || row >= N || col < 0 || col >= M)
		return false;
	else
		return true;
}

void printGrid()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

void calcSafeArea()
{
	//cout << "사각지대 크기 계산 수행" << endl;
	//printGrid();
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if(grid[i][j] == 0)
				count++;
		}
	}

	result = min(result, count);
}

void setCamDir(int idx, int dir)
{
	//cout << idx << "번 카메라 세팅" << endl;

	if (idx == cams.size())
	{
		calcSafeArea();
		return;
	}

	P pos = cams[idx];

	int initRow = pos.first;
	int initCol = pos.second;

	vector<P> changedPositions;

	int rotCount = grid[initRow][initCol];
	if(rotCount >= 3) rotCount--;

	// 카메라 종류에 따라 여러 방향으로 감시
	for (int rot = 0; rot < rotCount; rot++)
	{
		int nRow = initRow + dRow[dir];
		int nCol = initCol + dCol[dir];
		while (isInRange(nRow, nCol))
		{
			if(grid[nRow][nCol] == 6) // 벽일 경우 빠져나오기
				break;
			else if (grid[nRow][nCol] == 0) // 빈 공간일 경우 감시
			{
				grid[nRow][nCol] = 7;
				changedPositions.push_back({nRow, nCol});
			}
			else // 카메라일 경우 그냥 지나가기
			{
				// do nothing
			}

			nRow += dRow[dir];
			nCol += dCol[dir];
		}

		dir = (dir+1) % 4; // 방향 90도 돌리기
		if (grid[initRow][initCol] == 2) // 2번 타입 카메라일 경우 한번 더 돌리기
			dir = (dir + 1) % 4; // 방향 90도 돌리기
	}
	//cout << "감시 세팅 완료 " << endl;

	for (int i = 0; i < 4; i++)
	{
		setCamDir(idx+1, i);
	}

	// 원래 상태로 복구하기
	for (auto& pos : changedPositions)
	{
		grid[pos.first][pos.second] = 0;
	}
	return;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int input; cin >> input;
			if(1 <= input && input <= 5)
				cams.push_back({i,j});
			grid[i][j] = input;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		setCamDir(0, i);
	}

	cout << result;
}