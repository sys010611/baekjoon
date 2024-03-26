#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

int dp[100001][5][5]; // [idx][left][right]

int GetDP(int idx, int left, int right)
{
	int result = INF;

	//0에서
	if (dp[idx - 1][0][left] + 2 < result)
		result = dp[idx - 1][0][left] + 2;
	if (dp[idx - 1][right][0] + 2 < result)
		result = dp[idx - 1][right][0] + 2;

	// 인접
	for (int i = -3; i <= 3; i += 2)
	{
		if (left + i >= 0 && left + i < 5 && dp[idx - 1][left + i][right]+3 < result)
		{
			result = dp[idx - 1][left + i][right]+3;
		}
		if (right + i >= 0 && right + i < 5 && dp[idx - 1][left][right + i] + 3 < result)
		{
			result = dp[idx - 1][left][right + i] + 3;
		}
	}

	//제자리
	if (dp[idx - 1][left][right] + 1 < result)
	{
		result = dp[idx - 1][left][right] + 1;
	}

	//반대쪽
	for (int i = -2; i <= 2; i += 4)
	{
		if (left + i >= 0 && left + i < 5 && dp[idx - 1][left + i][right] + 4 < result)
		{
			result = dp[idx - 1][left + i][right] + 4;
		}
		if (right + i >= 0 && right + i < 5 && dp[idx - 1][left][right + i] + 4 < result)
		{
			result = dp[idx - 1][left][right + i] + 4;
		}
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(&dp[0][0][0], &dp[100000][4][5], INF);

	//base case
	dp[0][0][0] = 0;

	int curr;
	for(int idx = 1; idx <= INF; idx++)
	{
		cin >> curr;
		if (curr == 0)
		{
			int result = INF;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if(dp[idx-1][i][j] < result)
						result = dp[idx - 1][i][j];
				}
			}

			cout << result;
			return 0;
		}

		for (int other = 0; other < 5; other++)
		{
			// 이번 것을 왼발로 밟는다.
			dp[idx][curr][other] = GetDP(idx, curr, other);
			//printf("dp[%d][%d][%d] : %d\n", idx, curr, other, dp[idx][curr][other]);
			// 이번 것을 오른발로 밟는다.
			dp[idx][other][curr] = GetDP(idx, other, curr);
			//printf("dp[%d][%d][%d] : %d\n", idx, other, curr, dp[idx][other][curr]);
		}
	}
}