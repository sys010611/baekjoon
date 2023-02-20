#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

int coin[100];
int dp[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,k;
	cin >> n >> k;

	fill(dp,dp+10001, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - coin[i] >= 0)
			{
				dp[j] = dp[j] + dp[j - coin[i]];
			}
		}
	}

	cout << dp[k];
}