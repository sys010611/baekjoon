#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int result = 0;

typedef pair<int, bool> P; // <숫자, 결합 되었는지 여부>

static int LEFT = 0;
static int RIGHT = 1;
static int UP = 2;
static int DOWN = 3;

void printBoard(P board[][20])
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j].first << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/// <summary>
/// 결합 여부 초기화
/// </summary>
/// <param name="board"></param>
void ResetCompactCheck(P  board[][20])
{
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			board[i][j].second = false;
}

void PushLeft(P  board[][20])
{
	// 왼쪽
	for (int i = 0; i < n; i++) // 각 행마다
	{
		for (int rep = 0; rep < n; rep++) // 완전히 밀릴 때까지 n번 반복 필요
		{
			for (int j = 0; j < n - 1; j++) // 마지막 열 바로 전까지 반복
			{
				if (board[i][j].first == 0)
				{
					board[i][j] = board[i][j + 1];
					board[i][j + 1].first = 0;
					board[i][j + 1].second = false;
				}

				if (board[i][j] == board[i][j + 1] && board[i][j].second == false)
				{
					board[i][j].first += board[i][j + 1].first;
					board[i][j].second = true;
					board[i][j + 1].first = 0;
					board[i][j + 1].second = false;
				}

				// else : 아무것도 하지 않음
			}
		}
	}
}

void PushRight(P  board[][20])
{
	for (int i = 0; i < n; i++) // 각 행마다
	{
		for (int rep = 0; rep < n; rep++) // 완전히 밀릴 때까지 n번 반복 필요
		{
			for (int j = n - 1; j >= 1; j--) // 첫번째 열 바로 전까지 반복
			{
				if (board[i][j].first == 0)
				{
					board[i][j] = board[i][j - 1];
					board[i][j - 1].first = 0;
					board[i][j - 1].second = false;
				}

				if (board[i][j] == board[i][j - 1] && board[i][j].second == false)
				{
					board[i][j].first += board[i][j - 1].first;
					board[i][j].second = true;
					board[i][j - 1].first = 0;
					board[i][j - 1].second = false;
				}

				// else : 아무것도 하지 않음
			}
		}
	}
}

void PushUp(P  board[][20])
{
	for (int c = 0; c < n; c++) // 각 행마다
	{
		for (int rep = 0; rep < n; rep++) // 완전히 밀릴 때까지 n번 반복 필요
		{
			for (int r = 0; r < n - 1; r++) // 마지막 열 바로 전까지 반복
			{
				if (board[r][c].first == 0)
				{
					board[r][c] = board[r + 1][c];
					board[r + 1][c].first = 0;
					board[r + 1][c].second = false;
				}

				if (board[r][c] == board[r + 1][c] && board[r][c].second == false)
				{
					board[r][c].first += board[r + 1][c].first;
					board[r][c].second = true;
					board[r + 1][c].first = 0;
					board[r + 1][c].second = false;
				}

				// else : 아무것도 하지 않음
			}
		}
	}
}

void PushDown(P  board[][20])
{
	for (int c = 0; c < n; c++) // 각 행마다
	{
		for (int rep = 0; rep < n; rep++) // 완전히 밀릴 때까지 n번 반복 필요
		{
			for (int r = n - 1; r >= 1; r--) // 첫번째 열 바로 앞까지 반복
			{
				if (board[r][c].first == 0)
				{
					board[r][c] = board[r - 1][c];
					board[r - 1][c].first = 0;
					board[r - 1][c].second = false;
				}

				if (board[r][c] == board[r - 1][c] && board[r][c].second == false)
				{
					board[r][c].first += board[r - 1][c].first;
					board[r][c].second = true;
					board[r - 1][c].first = 0;
					board[r - 1][c].second = false;
				}

				// else : 아무것도 하지 않음
			}
		}
	}
}

void backtrack(int phase, P board[][20], int dir)
{
	//printBoard(board);

	//if(phase == 0)
	//	dir = DOWN;
	//else if(phase == 1)
	//	dir = RIGHT;
	//else
	//	dir = DOWN; //방향 고정

	if (phase == 5) // 끝까지 갔다면
	{
		//printBoard(board);

		//가장 큰 블록 저장
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				result = max(result, board[i][j].first);

		//이전 단계로
		//exit(0);
		return;
	}

	if (dir == UP)
	{
		PushUp(board);
		ResetCompactCheck(board);
		for (int i = 0; i < 4; i++)
		{
			P board_copy[20][20];
			copy(&board[0][0], &board[0][0] + 400, &board_copy[0][0]);
			backtrack(phase + 1, board_copy, i);
		}
	}
	if (dir == DOWN)
	{
		PushDown(board);
		ResetCompactCheck(board);
		for (int i = 0; i < 4; i++)
		{
			P board_copy[20][20];
			copy(&board[0][0], &board[0][0] + 400, &board_copy[0][0]);
			backtrack(phase + 1, board_copy, i);
		}
	}
	if (dir == LEFT)
	{
		PushLeft(board);
		ResetCompactCheck(board);
		for (int i = 0; i < 4; i++)
		{
			P board_copy[20][20];
			copy(&board[0][0], &board[0][0] + 400, &board_copy[0][0]);
			backtrack(phase + 1, board_copy, i);
		}
	}
	if (dir == RIGHT)
	{
		PushRight(board);
		ResetCompactCheck(board);
		for (int i = 0; i < 4; i++)
		{
			P board_copy[20][20];
			copy(&board[0][0], &board[0][0] + 400, &board_copy[0][0]);
			backtrack(phase+1, board_copy, i);
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	P board[20][20];

	cin >> n;

	int input;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			board[i][j] = P(input, false);
		}
	}

	for (int i = 0; i < 4; i++)
	{	
		P board_copy[20][20];
		copy(&board[0][0], &board[0][0]+400, &board_copy[0][0]);
		backtrack(0, board_copy, i);
	}


	cout << result;
}
