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

	int t; cin >> t; while (t--)
	{
		string s; cin >> s; 
		s.length() >= 6 && s.length() <= 9 ? cout << "yes" << endl : cout << "no" << endl;
	}
}