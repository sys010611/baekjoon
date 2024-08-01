#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dp, 0, sizeof(dp));

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < line.length(); j++)
		{
			arr[i][j+1] = line[j] - '0';
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 1)
			{
				int a = dp[i-1][j];
				int b = dp[i][j-1];
				int c = dp[i-1][j-1];

				dp[i][j] = (int)(min({a, b, c}) + 1);
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{

			//cout << dp[i][j] << " ";
			result = max(result, dp[i][j] * dp[i][j]);
		}
		//cout << endl;
	}
	
	cout << result;
}