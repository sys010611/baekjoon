#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s = "WelcomeToSMUPC";
	
	int n; cin >> n;  n %= 14;
	if (n == 0)
		n = 14;
	cout << s[n - 1];
		
}
