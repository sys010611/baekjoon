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

	float w, h;
	cin >> w >> h;
	
	cout.precision(1);
	cout << fixed;
	cout << w * h / 2.f;
}