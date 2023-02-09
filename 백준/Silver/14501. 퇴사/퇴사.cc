#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int dp[16];
int T[16];
int P[16];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t, p;
	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		cin >> t >> p;
		T[i] = t;
		P[i] = p;
	}

	fill(dp, dp+16, 0); //dp[i]: i일부터 일하여 최대 수익

	for (int i = n; i > 0; i--) //i: 현재 일수
	{
		if (i + T[i] - 1 > n) //i일차 상담이 불가능한 경우
		{
			dp[i] = dp[i+1];
		}
		else //i일차의 상담이 가능한 경우
		{
			dp[i] = max(dp[i+T[i]] + P[i], dp[i+1]); //i일차의 상담 수익 + 상담 이후의 수익
		}
	}

	/*for (int i = 1; i < n + 1; i++)
	{
		cout << "dp" << i << ": " << dp[i] << endl;
	}*/

	cout << dp[1];
}