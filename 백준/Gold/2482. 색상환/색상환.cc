#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define int long long

int N, K;
int dp[1001][1001];

const int DIV = 1000000003;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	memset(dp, 0, sizeof(dp));
	// base case
	for (int i = 1; i <= N; i++)
		dp[i][1] = i;
	
	for (int i = 4; i <= N; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i-2][j-1];
			dp[i][j] = dp[i][j] % DIV;
		}
	}

	cout << dp[N][K] % DIV;
}