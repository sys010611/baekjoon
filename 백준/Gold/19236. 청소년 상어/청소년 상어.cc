#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

int dRow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dCol[8] = {0, -1, -1, -1, 0, 1, 1, 1};

typedef pair<int,int> P; // <번호, 방향>
int result = -1;

void PrintGrid(P grid[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << grid[i][j].first << "/" << grid[i][j].second << " ";
		}
		cout << endl;
	}
}

// 모든 물고기를 조건에 맞게 이동시킨다.
void MoveFish(P grid[4][4])
{
	//cout << "물고기 이동 전:" << endl;
	//PrintGrid(grid);

	int row = 0;
	int col = 0;
	for (int currIdx = 1; currIdx <= 16; currIdx++)
	{
		bool moved = false;
		for (row = 0; row < 4; row++)
		{
			for (col = 0; col < 4; col++)
			{
				//cout << "Row : " << row << endl;
				//cout << "Col : " << col << endl;

				if (grid[row][col].first == currIdx)
				{
					//cout << currIdx << "번 물고기 발견"<< endl;
					int dir = grid[row][col].second;
					for (int count = 0; count < 7; count++)
					{
						dir = dir % 8;
						grid[row][col].second = dir;
						int nRow = row + dRow[dir];
						int nCol = col + dCol[dir];

						if (nRow < 0 || nRow >= 4 || nCol < 0 || nCol >= 4)
						{
							dir++;
							continue;
						}

						if (grid[nRow][nCol].first == 17) // 상어 존재
						{
							dir++;
							continue;
						}
						
						// 이동 가능
						std::swap(grid[row][col], grid[nRow][nCol]);
						moved = true;
						//cout << currIdx << "번 물고기 이동 완료" << endl;
						//PrintGrid(grid);
						break;
					}
				}
				if(moved)
					break;
			}
			if (moved)
				break;
		}
	}

	//cout << "모든 물고기 이동 완료, " << endl;
	//PrintGrid(grid);
}

// (row, col)로 이동시킨다.
void MoveShark(P grid[4][4], int row, int col, int score)
{
	//printf("상어 이동 : %d, %d\n", row, col);

	score += grid[row][col].first;
	//cout <<"현재 점수: " << score << endl;
	int nextDir = grid[row][col].second;

	grid[row][col].first = 17;

	//cout << "물고기 이동 시작"<< endl;
	MoveFish(grid);
	//cout << "물고기 이동 완료" << endl;
	
	for (int i = 1;i < 4; i++)
	{
		int nextRow = row + dRow[nextDir] * i;
		int nextCol = col + dCol[nextDir] * i;

		if(nextRow < 0 || nextRow >= 4 || nextCol < 0 || nextCol >= 4) // out of range
			continue;

		if(grid[nextRow][nextCol].first == -1)
			continue;

		//printf("%d, %d로 이동 가능\n", nextRow, nextCol);

		P newGrid[4][4];
		for(int row=0;row<4;row++)
			for(int col= 0;col<4;col++)
				newGrid[row][col] = grid[row][col];
		newGrid[row][col].first = -1; // 상어가 가고 난 자리는 비우기
		MoveShark(newGrid, nextRow, nextCol, score);
	}

	// 점수 계산 후 갱신
	//cout << "점수 계산 후 갱신" << endl;
	result = max(result, score);
}

signed main()
{
	P grid[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int no, dir;
			cin >> no >> dir;
			grid[i][j].first = no;
			grid[i][j].second = dir-1;
		}
	}

	MoveShark(grid, 0, 0, 0);

	cout << result;
}
