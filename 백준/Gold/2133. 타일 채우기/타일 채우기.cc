#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <climits>
#include <cmath>
#include <stack>
using namespace std;

#define int long long

int N;
int dp[31];

int DP(int n)
{
	if (dp[n] != -1)
		return dp[n];

	if (n % 2 == 1)
		return dp[n] = 0;

	int ret = 0;
	int initN = n;
	
	if (n > 2)
	{
		n -= 2;
		ret += DP(n) * 3;
	}
	while (n >= 2)
	{
		n -= 2;
		ret += DP(n) * 2;
	}

	return dp[initN] = ret;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N;

	// base case
	dp[0] = 1;
	dp[2] = 3;

	cout << DP(N);
}
