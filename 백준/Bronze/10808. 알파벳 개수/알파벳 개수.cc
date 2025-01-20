#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <cassert>
#include <map>
#include <set>
using namespace std;

int counts[100];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(counts, 0, sizeof(counts));

	string str;
	cin >> str;
	for (auto c : str)
		counts[c - 'a']++;

	for (int i = 'a'; i <= 'z'; i++)
	{
		cout << counts[i - 'a'] << " ";
	}
}
