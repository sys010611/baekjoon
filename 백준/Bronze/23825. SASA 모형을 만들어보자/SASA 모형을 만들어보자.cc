#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	cout << min(n / 2, m / 2);
}
