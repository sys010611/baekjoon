#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <deque>
#include <queue>
using namespace std;

int R, C, T;

int dRow[] = {0, -1, 0, 1};
int dCol[] = {1, 0, -1, 0};

queue<int> spreadQ[50][50];

int board[50][50];

void PrintBoard()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> T;

	// 공기 청정기의 위쪽 행
	int airFresherUpper = -1;
	// 공기 청정기의 아래쪽 행
	int airFresherLower = -1;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == -1)
			{
				if (airFresherUpper == -1)
					airFresherUpper = i;
				else
					airFresherLower = i;
			}
		}
	}

	//cout << "upper : " << airFresherUpper << endl;
	//cout << "lower : " << airFresherLower << endl;

	while (T--)
	{
		// 확산
		for (int row = 0; row < R; row++)
		{
			for (int col = 0; col < C; col++)
			{
				if (board[row][col] != 0 && board[row][col] != -1) // 미세먼지가 있었을 경우
				{
					int spreadCount = 0;
					int spreadAmount = board[row][col] / 5;
					for (int i = 0; i < 4; i++)
					{
						int nRow = row + dRow[i];
						int nCol = col + dCol[i];

						//out of bounds
						if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
							continue;
						// 확산하는 칸에 공기청정기가 있었을 경우
						if(board[nRow][nCol] == -1)
							continue;

						// 확산 가능
						//board[nRow][nCol] += spreadAmount;
						spreadQ[nRow][nCol].push(spreadAmount);
						spreadCount++;
					}

					board[row][col] -= spreadCount * spreadAmount;
				}
			}
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				while (!spreadQ[i][j].empty())
				{
					board[i][j] += spreadQ[i][j].front();
					spreadQ[i][j].pop();
				}
			}
		}

		//cout << "확산 후 : " << endl;
		//PrintBoard();

		// 작동
		// 윗부분 
		int currRow = airFresherUpper;
		int currCol = 0;
		
		currRow--; // 공기청정기 위 행부터 시작. 한 칸씩 공기청정기 쪽으로 당겨옴
		do // 위로
		{
			board[currRow][currCol] = board[currRow - 1][currCol];
			currRow--;
		}
		while(currRow > 0);

		do //오른쪽으로
		{
			board[currRow][currCol] = board[currRow][currCol+1];
			currCol++;
		}
		while(currCol < C-1);

		do //아래로
		{
			board[currRow][currCol] = board[currRow + 1][currCol];
			currRow++;
		} 
		while (currRow < airFresherUpper);
		
		do // 왼쪽으로
		{
			board[currRow][currCol] = board[currRow][currCol - 1];
			currCol--;
		} while (currCol > 1);
		board[currRow][currCol] = 0;


		// 아랫부분
		currRow = airFresherLower;
		currCol = 0;

		currRow++; // 공기청정기 아래 행부터 시작. 한 칸씩 공기청정기 쪽으로 당겨옴
		do // 아래로
		{
			board[currRow][currCol] = board[currRow + 1][currCol];
			currRow++;
		} while (currRow < R - 1);

		do //오른쪽으로
		{
			board[currRow][currCol] = board[currRow][currCol + 1];
			currCol++;
		} while (currCol < C - 1);

		do //위로
		{
			board[currRow][currCol] = board[currRow - 1][currCol];
			currRow--;
		} while (currRow > airFresherLower);

		do // 왼쪽으로
		{
			board[currRow][currCol] = board[currRow][currCol - 1];
			currCol--;
		} while (currCol > 1);
		board[currRow][currCol] = 0;

		//cout << "작동 후 : " << endl;
		//PrintBoard();
	}

	int result = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if(board[i][j] != -1)
				result += board[i][j];
		}
	}

	cout << result;
}