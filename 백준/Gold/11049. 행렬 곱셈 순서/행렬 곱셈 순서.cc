#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int N, r, c;

pair<int, int> matrices[500];
int dp[500][500]; // n ~ m까지의 곱셈 연산의 최소값

int Solve(int s, int e)
{
	if (dp[s][e] != -1)
	{
		return dp[s][e];
	}

	int ret = INT_MAX;
	for (int i = s; i <= e-1; i++)
	{
		ret = min(ret, Solve(s, i) + Solve(i + 1, e) + matrices[s].first * matrices[i].second * matrices[e].second);
	}
	return dp[s][e] = ret;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> matrices[i].first >> matrices[i].second;
	}

	memset(dp, -1, sizeof(dp));

	//base case
	for (int i = 0; i < N; i++)
	{
		dp[i][i] = 0;
	}

	cout << Solve(0, N - 1);
}