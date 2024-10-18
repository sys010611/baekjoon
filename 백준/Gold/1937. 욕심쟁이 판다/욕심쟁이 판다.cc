#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <limits>
using namespace std;

int n;
int map[500][500];
int dp[500][500]; // (n,m)에서 출발할 때 몇 칸 더 이동 가능한지

int dRow[4] = { 0, -1, 0, 1 };
int dCol[4] = { 1, 0, -1, 0 };

int solve(int row, int col)
{
	//printf("row : %d, col : %d\n", row, col);
	if (dp[row][col] != -1)
	{
		return dp[row][col];
	}

	int ret = 0; // base case 고려 필요 없음 (갈 곳이 없는 지역은 1 리턴)
	for (int i = 0; i < 4; i++)
	{
		int nRow = row + dRow[i];
		int nCol = col + dCol[i];

		if (nRow < 0 || nRow >= n || nCol < 0 || nCol >= n)
			continue;
		if (map[nRow][nCol] <= map[row][col])
			continue;

		ret = max(ret, solve(nRow, nCol));
	}

	return dp[row][col] = ret + 1;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	
	int result = -1; 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result = max(result, solve(i, j));
		}
	}

	cout << result;
}