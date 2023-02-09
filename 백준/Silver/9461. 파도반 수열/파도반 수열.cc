#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

long long dp[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;
	dp[7] = 4;
	dp[8] = 5;


	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;

		if (n <= 8)
		{
			cout << dp[n] << endl;
			continue;
		}

		for (int i = 9; i < n + 1; i++)
		{
			dp[i] = dp[i-1] + dp[i-5];
			//cout << "dp" << i << ": " << dp[i] << endl;
		}
		cout << dp[n] << endl;
	}
}