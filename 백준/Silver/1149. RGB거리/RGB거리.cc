#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int dp[1000][3]; //[n번째 집까지 칠했을때 비용][마지막 집의 색깔] (0:R 1:G 2:B)
int red[1000]; //n번째 집을 해당 색으로 칠하는데 드는 비용
int green[1000];
int blue[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> red[i] >> green[i] >> blue[i];
	}

	//base case
	dp[0][0] = red[0];
	dp[0][1] = green[0];
	dp[0][2] = blue[0];

	for (int i = 1; i < n - 1; i++) //마지막 집 바로 전까지
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + red[i];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + green[i];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + blue[i];
	}

	//마지막 집
	dp[n - 1][0] = min(dp[n - 2][1], dp[n - 2][2]) + red[n-1];
	dp[n - 1][1] = min(dp[n - 2][0], dp[n - 2][2]) + green[n-1];
	dp[n - 1][2] = min(dp[n - 2][0], dp[n - 2][1]) + blue[n-1];

	cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}