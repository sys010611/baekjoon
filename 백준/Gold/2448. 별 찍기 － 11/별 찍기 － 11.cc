#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#include <numeric>
#include <cstring>
using namespace std;

#define SIZE 7000

int N;
char grid[SIZE][SIZE];

void Draw(int n, int startRow, int startCol)
{
	if (n == 3)
	{
		grid[startRow][startCol + 2] = '*';
		grid[startRow + 1][startCol + 1] = '*';
		grid[startRow + 1][startCol + 3] = '*';

		for (int i = 0; i < 5; i++)
		{
			grid[startRow + 2][startCol + i] = '*';
		}
	}
	else
	{
		Draw(n/2, startRow, startCol + n/2);
		Draw(n/2, startRow + n/2, startCol);
		Draw(n/2, startRow + n/2, startCol + n);
	}
}

signed main()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			grid[i][j] = ' ';
		}
	}


	cin >> N;

	Draw(N, 0, 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N * 2; j++)
		{
			cout << grid[i][j];
		}
		cout << endl;
	}
}

