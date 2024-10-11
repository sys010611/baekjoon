#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int LIS[201];
int arr[201];
int N;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int r, s; cin >> r >> s;

	cout << 2 * s - r;
}