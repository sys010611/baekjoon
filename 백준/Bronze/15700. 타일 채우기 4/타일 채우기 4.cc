#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <climits>
#include <cmath>
#include <stack>
using namespace std;
#define int long long
int n, m;


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ret = 0;

	cin >> n >> m;

	if (n %2 == 0 && m%2 == 0) // 둘다 짝수
	{
		ret = n / 2 * m;
	}
	else if (n % 2 == 1) // n이 홀수
	{
		ret = (n - 1) / 2 * m + m / 2;
	}
	else if (m % 2 == 1) // m이 홀수
	{
		ret = (m - 1) / 2 * n + n / 2;
	}
	else // 둘다 홀수
	{
		ret = (n - 1) * (m - 1) * 2 + n / 2 + m / 2;
	}

	cout << ret;
}
