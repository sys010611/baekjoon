#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[1001][2][3];

#define DV 1000000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fill(&dp[0][0][0], &dp[1000][1][3], 0);

	cin >> N;

	//base case
	dp[1][0][0] = 1;
	dp[1][1][0] = 1;
	dp[1][0][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i][0][0]= dp[i - 1][0][0] % DV + dp[i - 1][0][1] % DV + dp[i - 1][0][2] % DV;
		dp[i][0][1] = dp[i - 1][0][0] % DV;
		dp[i][0][2] = dp[i - 1][0][1] % DV;
		
		dp[i][1][0] = dp[i - 1][0][0] % DV + dp[i - 1][0][1] % DV + dp[i - 1][0][2] % DV
			+ dp[i - 1][1][0] % DV + dp[i - 1][1][1] % DV + dp[i - 1][1][2] % DV;
		dp[i][1][1] = dp[i - 1][1][0] % DV;
		dp[i][1][2] = dp[i - 1][1][1] % DV;
	}

	int result = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result += dp[N][i][j] % DV;
		}
	}
	cout << result % DV;
}