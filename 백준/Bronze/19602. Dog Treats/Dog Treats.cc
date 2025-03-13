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

	int s, m, l; cin >> s >> m >> l;
	int num = 1 * s + 2 * m + 3 * l;
	if (num >= 10)
	{
		cout << "happy";
	}
	else
	{
		cout << "sad";
	}
}
