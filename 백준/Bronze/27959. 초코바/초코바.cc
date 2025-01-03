#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m; n *= 100;
	if (n >= m)cout << "Yes"; else cout << "No";
}

