#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <climits>
#include <cmath>
#include <stack>
using namespace std;


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s; cin >> s;
	if (s == "NLCS")
	{
		cout << "North London Collegiate School";
	}
	else if (s == "BHA")
	{
		cout << "Branksome Hall Asia";
	}
	else if (s == "KIS")
	{
		cout << "Korea International School";
	}
	else if (s == "SJA")
	{
		cout << "St. Johnsbury Academy";
	}
}
