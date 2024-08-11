#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

set<int> s;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin>> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		s.insert(input);
	}
	for(auto item : s)
		cout << item << " ";
}