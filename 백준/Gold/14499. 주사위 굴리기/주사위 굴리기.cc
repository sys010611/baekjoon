#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, x, y, K;
int grid[20][20];

int dRow[4] = {0, 0, -1, 1};
int dCol[4] = {1, -1, 0, 0};

int dice[7] = { 0, };

void moveDice(int command)
{
	command--; // 범위 조정

	// 위치 변경
	int nRow = x + dRow[command];
	int nCol = y + dCol[command];

	if(nRow<0 || nRow >= N || nCol<0||nCol>=M)
		return;

	x= nRow;
	y= nCol;


	// 회전 변경
	int newDice[7] = {0,};
	if (command == 0) // 오른쪽
	{
		newDice[1] = dice[4];
		newDice[2] = dice[2];
		newDice[3] = dice[1];
		newDice[4] = dice[6];
		newDice[5] = dice[5];
		newDice[6] = dice[3];
	}
	else if (command == 1) // 왼쪽
	{
		newDice[1] = dice[3];
		newDice[2] = dice[2];
		newDice[3] = dice[6];
		newDice[4] = dice[1];
		newDice[5] = dice[5];
		newDice[6] = dice[4];
	}
	else if (command == 2) // 위
	{
		newDice[1] = dice[5];
		newDice[2] = dice[1];
		newDice[3] = dice[3];
		newDice[4] = dice[4];
		newDice[5] = dice[6];
		newDice[6] = dice[2];
	}
	else if (command == 3) // 아래
	{
		newDice[1] = dice[2];
		newDice[2] = dice[6];
		newDice[3] = dice[3];
		newDice[4] = dice[4];
		newDice[5] = dice[1];
		newDice[6] = dice[5];
	}

	for(int i=0;i<7;i++)
		dice[i] = newDice[i];

	if (grid[x][y] == 0) // 칸에 쓰인 수가 0이라면, 주사위 바닥면 값을 복사
	{
		grid[x][y] = dice[6];
	}
	else // 아니라면 칸의 수가 주사위의 바닥면으로 복사
	{
		//cout << "주사위의 바닥면으로 " << grid[x][y] << "복사" << endl;
		dice[6] = grid[x][y];
		grid[x][y] = 0;
	}

	cout << dice[1] << endl;
}

int main()
{
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> grid[i][j];

	for (int i = 0; i < K; i++)
	{
		int command;
		cin >> command;

		moveDice(command);
	}
}