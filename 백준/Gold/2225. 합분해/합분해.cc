#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define DIV 1000000000

int N, K;
int dp[201][201];

int GetDP(int n, int m)
{
	if(dp[n][m] != -1)
		return dp[n][m];

	int ret = 0;
	for (int i = 0; i <= n; i++)
	{
		ret += GetDP(n-i, m-1);
		ret %= DIV;
	}

	return dp[n][m] = ret;
}

signed main()
{
	cin >> N >> K;

	memset(dp, -1, sizeof(dp));

	//base case
	for (int i = 0; i <= N; i++)
	{
		dp[i][0] = 0;
		dp[i][1] = 1;
	}

	cout << GetDP(N, K);

	//for (int i = 0; i <= N; i++)
	//{
	//	for (int j = 0; j < K; j++)
	//	{
	//		printf("dp %d %d : %d ", i, j, dp[i][j]);
	//	}
	//	cout << endl;
	//}
}