#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

signed main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str; cin >> str;
		int s,e;
		cin>>s>>e;

		for (int i = 0; i < str.length(); i++)
		{
			if(s <= i && i < e)
				continue;
			else
			{
				cout << str[i];
			}
		}
		cout << endl;
	}
}
