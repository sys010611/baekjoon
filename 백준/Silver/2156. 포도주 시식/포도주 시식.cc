#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
int arr[10000];
int dp[10000][3];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, 0, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//base case
	dp[0][0] = 0;
	dp[0][1] = arr[0];
	dp[0][2] = arr[0];
	dp[1][0] = 0;
	dp[1][1] = arr[1];
	dp[1][2] = arr[0] + arr[1];

	for (int i = 2; i < n; i++)
	{
		int curr = arr[i];

		dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
		dp[i][1] = max({dp[i-2][0], dp[i-2][1], dp[i-2][2]}) + curr;
		dp[i][2] = dp[i-1][1] + curr;
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j <= 2; j++)
	//	{
	//		printf("dp %d %d : %d / ", i, j, dp[i][j]);
	//	}
	//	cout << endl;
	//}

	cout << *max_element(&dp[0][0], &dp[9999][3]);
}