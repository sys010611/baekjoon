#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	set<int> S;

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		S.insert(input);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int findingNum;
		cin >> findingNum;
		if (S.find(findingNum) == S.end())
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << 1 << "\n";
		}
	}
}