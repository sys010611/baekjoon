#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int dp[1000][3][3]; //[n번째 집까지 칠했을때 비용][마지막 집의 색깔][첫번째 집의 색깔] (0:R 1:G 2:B)
int red[1000]; //n번째 집을 해당 색으로 칠하는데 드는 비용
int green[1000];
int blue[1000];

const int INF = 100000000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> red[i] >> green[i] >> blue[i];
	}

	fill(&dp[0][0][0], &dp[999][2][3], INF);

	//base case
	dp[0][0][0] = red[0];
	dp[0][1][1] = green[0];
	dp[0][2][2] = blue[0];

	for (int i = 1; i < n - 1; i++) //마지막 집 바로 전까지
	{
		for (int j = 0; j < 3; j++)
		{
			dp[i][0][j] = min(dp[i - 1][1][j], dp[i - 1][2][j]) + red[i];
			dp[i][1][j] = min(dp[i - 1][0][j], dp[i - 1][2][j]) + green[i];
			dp[i][2][j] = min(dp[i - 1][0][j], dp[i - 1][1][j]) + blue[i];
		}
	}

	//마지막 집
	dp[n - 1][0][1] = min(dp[n - 2][1][1], dp[n - 2][2][1]) + red[n - 1];
	dp[n - 1][0][2] = min(dp[n - 2][1][2], dp[n - 2][2][2]) + red[n - 1];
	dp[n - 1][1][0] = min(dp[n - 2][0][0], dp[n - 2][2][0]) + green[n - 1];
	dp[n - 1][1][2] = min(dp[n - 2][0][2], dp[n - 2][2][2]) + green[n - 1];
	dp[n - 1][2][0] = min(dp[n - 2][1][0], dp[n - 2][0][0]) + blue[n - 1];
	dp[n - 1][2][1] = min(dp[n - 2][1][1], dp[n - 2][0][1]) + blue[n - 1];


	int result = INF;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//cout << dp[n - 1][i][j] << endl;
			if (dp[n - 1][i][j] < result)
			{
				result = dp[n - 1][i][j];
			}
		}
	}

	//cout << endl;
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		cout << dp[i][j][1] << " ";
	//	}
	//	cout << endl;
	//}

	cout << result;
}

