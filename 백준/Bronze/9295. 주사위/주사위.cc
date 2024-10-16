#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <limits>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int a, b; cin >> a >> b;
		cout << "Case " << i << ": " << a + b << endl;;

	}
}