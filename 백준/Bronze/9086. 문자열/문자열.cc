#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;


signed main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		cout << str[0] << str[str.size() - 1] << endl;
	}
}
