#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int P[1001];
int dp[1001];

// 카드 n개를 사는데 드는 최대비용 구하기
int GetPrice(int n)
{
	if (n == 0)
		return 0;
	if (dp[n] != -1)
		return dp[n];

	int ret = -1;
	for (int i = 1; i <= n; i++)
	{
		ret = max(ret, P[i] + GetPrice(n - i));
	}
	return dp[n] = ret;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> P[i];
	}

	cout << GetPrice(N);
}
