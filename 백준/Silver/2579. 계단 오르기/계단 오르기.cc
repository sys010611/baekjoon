#include <iostream>
#include <vector>
using namespace std;

int score[301];
int dp[301];

int main()
{
	int n; //계단 개수
	cin >> n;

	for (int i = 1; i < n+1; i++)
	{
		cin >> score[i];
	}

	for (int i = 0; i < 301; i++)
		dp[i] = -1;

	dp[1] = score[1];
	dp[2] = score[1]+score[2];
	dp[3] = max(score[1]+score[3], score[2]+score[3]);

	for (int i = 1; i < 4; i++)
	{
		//cout << "dp" << i << ": " << dp[i] << endl;
	}
	for (int i = 4; i < n + 1; i++)
	{
		dp[i] = max(dp[i-3] + score[i-1] + score[i], dp[i-2]+score[i]);
		//cout << "dp" << i << ": " << dp[i] << endl;
	}

	cout << dp[n];
}