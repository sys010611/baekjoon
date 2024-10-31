#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;cin>>str;

	for (int i = 0; i < str.length()/2; i++)
	{
		if (str[i] != str[str.length() - 1 - i])
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}
