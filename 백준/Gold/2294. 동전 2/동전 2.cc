#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int n, k;
int dp[100001];
int coin[10000];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(dp, dp + 10001, -1);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
		//base case
		dp[coin[i]] = 1;
	}
	dp[0] = 0;

	for (int i = 1; i <= k; i++)
	{
		if(dp[i] == 1)
			continue;
		int min = 100000000;
		for (int j = 0; j < n; j++)
		{
			if(i-coin[j]<0)
				continue;
			if (dp[i-coin[j]] != -1)
			{
				if (dp[i - coin[j]] < min)
				{
					min = dp[i - coin[j]];
				}
			}
		}
		if (min == 100000000)
		{
			dp[i] = -1;
		}
		else
		{
			dp[i] = min + 1;
		}
	}

	/*for (int i = 0; i < k + 1; i++)
	{
		cout << "dp" << i << ": " << dp[i] << endl;
	}*/
	cout << dp[k];
}