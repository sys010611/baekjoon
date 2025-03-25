#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <climits>
#include <cmath>
#include <stack>
using namespace std;

int N;
int A[1001];
int dp[1001]; // dp[n] : n번째 숫자를 사용하여 가능한 최대 총합

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, 0, sizeof(dp));
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		// base case
		dp[i] = A[i];
	}

	for (int i = 0; i < N; i++)
	{
		int curr = A[i];
		for (int j = 0; j < i; j++)
		{
			int prev = A[j];
			if (prev < curr) // 붙이기 가능
			{
				dp[i] = max(dp[i], dp[j] + curr);
			}
		}
	}

	cout << *max_element(dp, dp + N);
}
