#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int dp[5000];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	fill(dp, dp+5000, -1);

	dp[3] = 1;
	dp[5] = 1;

	for (int i = 6; i < n+1; i++)
	{
		if (dp[i - 5] != -1)
		{
			dp[i] = dp[i-5] + 1;
		}
		else if (dp[i - 3] != -1)
		{
			dp[i] = dp[i-3] + 1;
		}
	}

	/*for (int i = 0; i < n + 1; i++)
	{
		cout << "dp" << i << ": " << dp[i] << endl;
	}*/

	cout << dp[n];

}