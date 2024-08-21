#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 1000000

int N;
int dp[61][61][61];
int damage[3] = {1, 3, 9};
int scv[3];

int backtrack(int n, int m, int k)
{
	n = max(n, 0);
	m = max(m, 0);
	k = max(k, 0);

	if(dp[n][m][k] != -1)
		return dp[n][m][k];

	int ret = INF;

	do
	{
		ret = min(ret, backtrack(n-damage[0], m-damage[1], k-damage[2]));
	} while (next_permutation(damage, damage + 3));

	return dp[n][m][k] = ret + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	cin >> N;

	//base case
	do
	{
		for (int i = 0; i <= damage[0]; i++)
		{
			for (int j = 0; j <= damage[1]; j++)
			{
				for (int k = 0; k <= damage[2]; k++)
				{
					dp[i][j][k] = 1;
				}
			}
		}
	}
	while(next_permutation(damage, damage+3));

	fill(scv, scv+3, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> scv[i];
	}

	cout << backtrack(scv[0], scv[1], scv[2]);
}