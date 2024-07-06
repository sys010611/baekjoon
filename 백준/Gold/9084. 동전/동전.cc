#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[20][10001]; // n번 코인까지 고려했을 때 m원을 만드는 경우의 수

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> coins;
		for (int i = 0; i < n; i++)
		{
			int coin;
			cin >> coin;
			coins.push_back(coin);
		}

		int m;
		cin >> m;

		fill(&dp[0][0], &dp[19][10001], 0);

		//base case
		for (int i = 0; i <= m; i++) // 0번째 동전까지만 고려하는 경우
		{
			if (i % coins[0] == 0)
				dp[0][i] = 1;
		}

		for (int i = 1; i < coins.size(); i++)
		{
			int coin = coins[i];
			for (int price = 0; price <= m; price++)
			{
				if (coin > price) // 어차피 이번 동전은 사용 못하는 경우
				{
					dp[i][price] = dp[i-1][price];
				}
				else // 이번 동전을 사용할 수도 있는 경우
				{
					dp[i][price] = dp[i-1][price] + (dp[i][price-coin]);
				}
			}
		}

		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j <= m; j++)
		//	{
		//		cout << dp[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		cout << dp[n-1][m] << endl;
	}
}