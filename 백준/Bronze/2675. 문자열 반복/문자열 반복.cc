#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#include <cstring>
#include <bitset>
#include <set>
using namespace std;


signed main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int r;
		string s;

		cin >> r >> s;

		for (auto c : s)
		{
			for (int i = 0; i < r; i++)
			{
				cout << c;
			}
		}
		cout << endl;
	}
}


