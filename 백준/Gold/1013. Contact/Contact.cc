#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <regex>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin>>t;
	while (t--)
	{
		string s;
		cin >> s;

		regex R("(100+1+|01)+");

		if(regex_match(s, R))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}