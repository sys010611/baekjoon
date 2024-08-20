#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[4001][4001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dp, 0, sizeof(dp));

	string A, B;

	cin >> A >> B;

	for (int i = 1; i <= A.length(); i++)
	{
		for (int j = 1; j <= B.length(); j++)
		{
			char a = A[i-1];
			char b = B[j-1];

			if(a == b)
				dp[i][j] = dp[i-1][j-1] + 1;

			else
				dp[i][j] = 0;
		}
	}

	//for (int i = 0; i <= A.length(); i++)
	//{
	//	for (int j = 0; j <= B.length(); j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cout << *max_element(&dp[0][0], &dp[4000][4001]);
}