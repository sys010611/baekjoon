#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#include <cstring>
#include <set>
using namespace std;

int board[10][10];

bool Check(int row, int col)
{
	bool used[10];

	fill(used, used + 10, false);
	for (int i = 0; i < 9; i++)
	{
		int currNum = board[row][i];
		if (currNum != 0 && used[currNum])
		{
			//cout << "row 체크 실패" << endl;
			return false;
		}
		else
		{
			used[currNum] = true;
		}
	}

	fill(used, used + 10, false);
	for (int i = 0; i < 9; i++)
	{
		int currNum = board[i][col];
		if (currNum != 0 && used[currNum])
		{
			//cout << "col 체크 실패" << endl;
			return false;
		}
		else
		{
			used[currNum] = true;
		}
	}

	// 3x3 체크
	fill(used, used + 10, false);
	int startRow = row / 3 * 3;
	int startCol = col / 3 * 3;
	//printf("sRow : %d, sCol : %d\n", startRow, startCol);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int currNum = board[startRow + i][startCol + j];
			if (currNum != 0 && used[currNum])
			{
				//cout << "3x3 체크 실패" << endl;
				return false;
			}
			else
			{
				used[currNum] = true;
			}
		}
	}
	return true;
}

void Backtrack(int row, int col)
{
	//printf("%d, %d\n", row, col);

	//for (int i = 0; i < 9; i++)
	//{
	//	for (int j = 0; j < 9; j++)
	//	{
	//		cout << board[i][j];
	//	}
	//	cout << endl;
	//}


	if (row > 8) // 성공
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j];
			}
			cout << endl;
		}
		exit(0);
	}

	if (board[row][col] != 0)
	{
		if (col == 8)
		{
			Backtrack(row + 1, 0);
		}
		else
		{
			Backtrack(row, col + 1);
		}
	}
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			board[row][col] = i;
			//cout << i << "가능?  " ;
			if (Check(row, col))
			{
				//cout << "가능" << endl;
				if (col == 8)
				{
					Backtrack(row + 1, 0);
				}
				else
				{
					Backtrack(row, col + 1);
				}
			}
			else
			{
				//cout << "불가능" << endl;
				continue;
			}
		}

		//cout << "돌아가기 " << endl;
		board[row][col] = 0;
		return;
	}

	
}

signed main()
{
	for (int i = 0; i < 9; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = s[j] - '0';
		}
	}

	Backtrack(0, 0);
}

