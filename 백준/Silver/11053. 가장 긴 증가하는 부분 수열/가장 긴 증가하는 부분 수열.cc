#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001];
int arr[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	fill(dp, dp+1001, 1);
	dp[1] = 1;

	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j]+1;
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dp[i] > max)
		{
			max = dp[i];
		}
	}

	cout << max << endl;
}