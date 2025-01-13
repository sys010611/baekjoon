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

	int diff = 'a' - 'A';

	string a;
	string b = "";
	cin >> a;

	for (auto c : a)
	{
		if ('a' <= c && c <= 'z')
		{
			b.push_back(c - diff);
		}
		else if ('A' <= c && c <= 'Z')
		{
			b.push_back(c + diff);
		}
	}

	cout << b;
}