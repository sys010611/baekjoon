#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

priority_queue<int> Q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		if (x > 0)
		{
			Q.push(x);
		}
		else if (x == 0)
		{
			if (Q.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << Q.top() << "\n";
				Q.pop();
			}
		}
	}
}