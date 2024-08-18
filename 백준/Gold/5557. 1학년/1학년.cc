#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define int long long

int N;
vector<int> arr;
int dp[100][21];

int DP(int n, int m)
{
	if (n < 0 || m < 0 || m > 20)
		return 0;


	if (dp[n][m] != -1)
	{
		return dp[n][m];
	}

	dp[n][m] = 0;

	if (0 <= m - arr[n] && m - arr[n] <= 20)
	{
		int ret = DP(n - 1, m - arr[n]);
		if (ret != -1)
		{
			dp[n][m] += ret;
		}
	}

	if (0 <= m + arr[n] && m + arr[n] <= 20)
	{
		int ret = DP(n - 1, m + arr[n]);
		if (ret != -1)
		{
			dp[n][m] += ret;
		}
	}

	return dp[n][m];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int ans = arr[N-1];

	// base case
	dp[0][arr[0]] = 1;

	cout << DP(N-2, ans);
}