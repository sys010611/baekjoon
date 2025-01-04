#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

string S;
int dp[2501][2501];
int F[2501];

#define INF 1000000

int DP(int s, int e)
{
	if (s > e)
		return 0;

	if (dp[s][e] != -1)
		return dp[s][e];

	// base case
	if (s == e)
	{
		return dp[s][e] = 1;
	}
	else if (s + 1 == e)
	{
		if (S[s] == S[e])
			return dp[s][e] = 1;
		else
			return dp[s][e] = 0;
	}

	if (S[s] == S[e])
	{
		return dp[s][e] = DP(s+1, e-1);
	}
	else
	{
		return dp[s][e] = 0;
	}
}

int Check(int e)
{
	if (e < 0)
		return 0;

	if (F[e] != INF)
		return F[e];

	for (int i = 0; i <= e; i++)
	{
		if (DP(i, e) == 1)
		{
			F[e] = min(F[e], 1 + Check(i - 1));
		}
	}
	return F[e];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S;

	memset(dp, -1, sizeof(dp));
	fill(F, F + 2501, INF);

	cout << Check(S.length() - 1);
}

