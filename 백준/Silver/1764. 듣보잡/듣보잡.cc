#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_set<string> heard;
	unordered_set<string> seen;
	set<string> both;
	unordered_set<string>::iterator it;
	set<string>::iterator it2;

	int n,m;
	cin >> n >> m;

	while (n--)
	{
		string input;
		cin >> input;
		heard.insert(input);
	}
	while (m--)
	{
		string input;
		cin >> input;
		seen.insert(input);
	}

	for (string curr : heard)
	{
		it = seen.find(curr);
		if (it != seen.end())
		{
			both.insert(*it);
		}
		else
		{
			continue;
		}
	}

	cout << both.size() << endl;
	for (it2 = both.begin(); it2 != both.end(); it2++)
	{
		cout << *it2 << endl;
	}
}