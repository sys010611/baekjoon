#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

char board[50][50];

int check(int startCol, int startRow) //8x8 판 내부 사각형의 변경 횟수 세기 (i, j: 왼쪽 위 시작점)
{
	//cout << "시작점: " << startCol << " " << startRow << endl;

	int count1=0; //시작점을 W로할때 변경횟수
	int count2=0; //시작점을 H로 할때 변경횟수

	//시작점을 W로 하는 경우
	//B가 되는 칸
	for (int i = 0 + startCol; i < 8 + startCol; i += 2)
	{
		for (int j = 1 + startRow; j < 8 + startRow; j += 2)
		{
			if (board[i][j] == 'W')
			{
				count1++;
			}
		}
	}
	for (int i = 1 + startCol; i < 8 + startCol; i += 2)
	{
		for (int j = 0 + startRow; j < 8 + startRow; j += 2)
		{
			if (board[i][j] == 'W')
			{
				count1++;
			}
		}
	}
	//W가 되는 칸
	for (int i = 0 + startCol; i < 8 + startCol; i += 2)
	{
		for (int j = 0 + startRow; j < 8 + startRow; j += 2)
		{
			if (board[i][j] == 'B')
			{
				count1++;
			}
		}
	}
	for (int i = 1 + startCol; i < 8 + startCol; i += 2)
	{
		for (int j = 1 + startRow; j < 8 + startRow; j += 2)
		{
			if (board[i][j] == 'B')
			{
				count1++;
			}
		}
	}

	//시작점을 H로 하는 경우
	//B가 되는 칸
	for (int i = 0 + startCol; i < 8 + startCol; i += 2)
	{
		for (int j = 0 + startRow; j < 8 + startRow; j += 2)
		{
			if (board[i][j] == 'W')
			{
				count2++;
			}
		}
	}
	for (int i = 1 + startCol; i < 8 + startCol; i += 2)
	{
		for (int j = 1 + startRow; j < 8 + startRow; j += 2)
		{
			if (board[i][j] == 'W')
			{
				count2++;
			}
		}
	}
	//W가 되는 칸
	for (int i = 0 + startCol; i < 8 + startCol; i += 2)
	{
		for (int j = 1 + startRow; j < 8 + startRow; j += 2)
		{
			if (board[i][j] == 'B')
			{
				count2++;
			}
		}
	}
	for (int i = 1 + startCol; i < 8 + startCol; i += 2)
	{
		for (int j = 0 + startRow; j < 8 + startRow; j += 2)
		{
			if (board[i][j] == 'B')
			{
				count2++;
			}
		}
	}

	//cout << "count1: "<<  count1 << "  count2: " << count2 << endl;

	return min(count1, count2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin >> n >> m; //세로, 가로

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	/*cout << endl; //체스판 확인
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}*/
	//cout << endl << endl;

	int result = INT_MAX;

	for (int i = 0; i <= n - 8; i++) //i,j: 가장 왼쪽 위 꼭짓점
	{
		for (int j = 0; j <= m - 8; j++)
		{
			result = min(result, check(i,j));
		}
	}

	cout << result;
}