#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b; cin >> a >> b; a < b ? cout << -1 : a>b ? cout << 1 : cout << 0;
}