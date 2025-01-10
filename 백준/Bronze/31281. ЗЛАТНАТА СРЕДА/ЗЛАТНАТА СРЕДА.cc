#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
using namespace std;

#define int long long

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a[3];
	for (int i = 0; i < 3; i++)
		cin >> a[i];
	sort(a, a + 3);
	cout << a[1];
}