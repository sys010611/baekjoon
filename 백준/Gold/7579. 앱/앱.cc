#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

#define INF 1000000000

int N, M;
vector<int> mem;
vector<int> cost;

int dp[100][10001]; // i번째 앱까지 고려, j의 cost로 얼마만큼의 메모리를 확보 가능한지

int main()
{
	cin >> N >> M;
	mem.resize(N);
	for (int i = 0; i < N; i++)
		cin >> mem[i];
	cost.resize(N);
	for (int i = 0; i < N; i++)
		cin >> cost[i];

	memset(dp, 0, sizeof(dp));

	// 첫번째 앱만 고려
	for (int i = 0; i <= 10000; i++)
	{
		if (cost[0] <= i)
		{
			dp[0][i] = mem[0];
		}
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= 10000; j++)
		{
			if (cost[i] <= j)
			{
				dp[i][j] = max(dp[i-1][j], mem[i] + dp[i-1][j-cost[i]]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	//cout << "dp 0 0: " << dp[0][0] << endl;

	for (int i = 0; i <= 10000; i++)
	{
		if (dp[N - 1][i] >= M)
		{
			//cout << "dp " <<N-1 << "," << i << " : " << dp[N-1][i] << endl;
			cout << i;
			return 0;
		}
	}

}