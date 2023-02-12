#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int dp[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(dp, dp+100001, 100000000);

	for (int i = 1; i < 317; i++)
	{
		dp[i*i] = 1;
	}

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	int n, min;
	cin >> n;

	for (int i = 5; i < n + 1; i++)
	{
		if (dp[i] != 100000000)
			continue;
		for (int j = 1; j * j < i; j++)
		{
			if (dp[i] > dp[i - j * j] + 1)
			{
				dp[i] = dp[i- j*j]+1;
			}

		}
	}

	/*for (int i = 1; i < n + 1; i++)
	{
		cout << "dp" << i << ": " << dp[i] << endl;
	}*/

	cout << dp[n];
}