#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <assert.h>
#include <climits>
using namespace std;

int dp[16][16][3];
int N;
int map[16][16];

bool IsSafe(int row, int col)
{
	return row >= 0 && col >= 0 && map[row][col] == 0;
}

int Solve(int row, int col, int dir)
{
	if (row < 0 || col < 0)
		return 0;

	if (map[row][col] == 1)
		return dp[row][col][dir] = 0;

	if (dp[row][col][dir] != -1)
	{
		return dp[row][col][dir];
	}

	int ret = 0;
	if (dir == 0)
	{
		ret += Solve(row, col - 1, 0) + Solve(row, col - 1, 1);
	}
	else if (dir == 1)
	{
		if (IsSafe(row - 1, col) && IsSafe(row, col - 1))
		{
			ret += Solve(row - 1, col - 1, 0);
			ret += Solve(row - 1, col - 1, 1);
			ret += Solve(row - 1, col - 1, 2);
		}
	}
	else // dir == 2
	{
		ret += Solve(row - 1, col, 1) + Solve(row - 1, col, 2);
	}
	return dp[row][col][dir] = ret;
}

void PrintDP()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int ret = 0;
			for (int k = 0; k < 3; k++)
			{
				ret += dp[i][j][k];
			}
			cout << ret << " ";
		}
		cout << endl;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	//base case
	dp[0][1][0] = 1;

	int ret = 0;
	for (int i = 0; i < 3; i++)
	{
		ret += Solve(N - 1, N - 1, i);
	}

	cout << ret << endl;

	//PrintDP();
}