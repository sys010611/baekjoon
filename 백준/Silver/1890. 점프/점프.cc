#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define int long long

int N;
int grid[100][100];
int dp[100][100];

int GetPathCount(int row, int col)
{
	if (dp[row][col] != -1)
	{
		return dp[row][col];
	}

	int ret = 0;

	// 위 방향으로 탐색
	for (int i = 1; i < 100; i++)
	{
		int prevRow = row-i;
		int prevCol = col;

		if(prevRow < 0)
			break;

		if (grid[prevRow][prevCol] == i)
			ret += GetPathCount(prevRow, prevCol);
	}

	// 왼쪽 방향으로 탐색
	for (int i = 1; i < 100; i++)
	{
		int prevRow = row;
		int prevCol = col - i;

		if (prevCol < 0)
			break;

		if (grid[prevRow][prevCol] == i)
			ret += GetPathCount(prevRow, prevCol);
	}

	return dp[row][col] = ret;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	//base case
	dp[0][0] = 1;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> grid[i][j];
		}
	}

	cout << GetPathCount(N-1, N-1) << endl;

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}
}