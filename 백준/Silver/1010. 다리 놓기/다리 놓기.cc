#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int dp[31][31];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n,m;
		cin >> n >> m;

		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < m+1; j++)
			{
				dp[i][j] = 0;
			}
		}

		for (int i = 1; i < m - n + 2; i++)
		{
			dp[1][i] = i;
		}
		
		for (int i = 2; i < n + 1; i++)
		{
			for (int j = i; j < i + m - n + 1; j++)
			{
				for (int k = i - 1; k < j; k++)
				{
					dp[i][j] += dp[i-1][k];
				}
			}
		}

		cout << dp[n][m] << endl;
	}
}