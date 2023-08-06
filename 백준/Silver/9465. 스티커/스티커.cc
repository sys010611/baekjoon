#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[2][100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		fill(dp[0], dp[0] + 100001, 0);
		fill(dp[1], dp[1] + 100001, 0);

		int n;
		cin >> n;

		int** score = new int* [2];
		for(int i=0;i<2;i++)
			score[i] = new int[n+1];

		for (int i = 1; i <= n; i++) //dp테이블과 인덱스 맞추기 위해 1열은 비워둠
			cin >> score[0][i];
		for (int i = 1; i <= n; i++)
			cin >> score[1][i];

		//base case
		dp[0][1] = score[0][1];
		dp[1][1] = score[1][1];

		for (int i = 2; i <= n; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + score[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + score[1][i];
		}

		cout << max(dp[0][n], dp[1][n]) << endl;
	}
}