#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b; cin >> a >> b;
	a *= 7; b *= 13;

	if (a > b)
	{
		cout << "Axel";
	}
	else if (a < b)
	{
		cout << "Petra";
	}
	else
		cout << "lika";
}

