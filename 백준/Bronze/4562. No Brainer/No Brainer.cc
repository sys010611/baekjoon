#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		if (x >= y)
		{
			cout << "MMM BRAINS" << endl;
		}
		else
		{
			cout << "NO BRAINS" << endl;
		}
	}
}
