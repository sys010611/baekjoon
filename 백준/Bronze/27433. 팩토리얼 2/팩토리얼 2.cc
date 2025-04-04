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

#define int long long

int N, M;
int A[100001];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 1;
	int n; cin >> n;
	for (int i = n; i >= 1; i--)
	{
		ans *= i;
	}
	cout << ans;
}
