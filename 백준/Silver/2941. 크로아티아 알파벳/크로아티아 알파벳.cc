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

	string s;
	cin >> s;

	int count = 0;

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];

		if (c == 'c')
		{
			if (i + 1 < s.length())
			{
				if (s[i + 1] == '=' || s[i+1] == '-')
				{
					count++; i++;
					continue;
				}
			}
		}

		if (c == 'd')
		{
			if (i + 1 < s.length() && s[i + 1] == '-')
			{
				count++; i++;
				continue;
			}
			if (i + 2 < s.length() && s[i + 1] == 'z' && s[i + 2] == '=')
			{
				count++; i+=2;
				continue;
			}
		}
		if (c == 'l')
		{
			if (i + 1 < s.length() && s[i + 1] == 'j')
			{
				count++; i++;
				continue;
			}
		}
		if (c == 'n')
		{
			if (i + 1 < s.length() && s[i + 1] == 'j')
			{
				count++; i++;
				continue;
			}
		}
		if (c == 's')
		{
			if (i + 1 < s.length() && s[i + 1] == '=')
			{
				count++; i++;
				continue;
			}
		}
		if (c == 'z')
		{
			if (i + 1 < s.length() && s[i + 1] == '=')
			{
				count++; i++;
				continue;
			}
		}

		if('a' <= s[i] && s[i] <= 'z')
			count++;
	}

	cout << count;
}