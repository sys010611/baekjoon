#include <iostream>
#include <queue>
#include <unordered_set>
#include <cstring>
using namespace std;

signed main()
{
	string str;
	cin >> str;
	for (auto it = str.rbegin(); it != str.rend(); it++)
	{
		cout << *it;
	}
}
