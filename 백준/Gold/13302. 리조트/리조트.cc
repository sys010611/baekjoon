#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define INF 1000000

int N, M;
bool canUse[101];
int ret = 0;
int dp[101][202]; // [현재 일자][쿠폰 개수]

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(canUse, canUse + 101, true);
	
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 202; j++)
			dp[i][j] = INF;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int input;
		cin >> input;
		canUse[input] = false;
	}

	// base case
	dp[0][0] = 0;

	for (int i = 0; i <= N; i++)
	{
		int dayMin = INF;
		for (int j = 0; j < 202; j++)
		{
			dayMin = min(dayMin, dp[i][j]);

			if (!canUse[i + 1])
			{
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			}
			else
			{
				// 1일권
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 10000);

				// 쿠폰 사용
				if (j >= 3)
					dp[i + 1][j - 3] = min(dp[i + 1][j - 3], dp[i][j]);
			}

			

			// 3일권
			dp[i + 3][j + 1] = min(dp[i + 3][j + 1], dp[i][j] + 25000);

			// 5일권
			dp[i + 5][j + 2] = min(dp[i + 5][j + 2], dp[i][j] + 37000);
		}

		//cout << i << "일 째 최소 비용 : " << dayMin << endl;
	}

	int ret = INF;
	for (int i = 0; i < 202; i++)
	{
		ret = min(ret, dp[N][i]);
	}
	cout << ret;
}
