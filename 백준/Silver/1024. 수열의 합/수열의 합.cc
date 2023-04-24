#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, l;
	cin >> n >> l;

	while (true)
	{
		if (l > 100)
		{
			cout << -1;
			return 0;
		}

		int x = n - l*(l+1)/2;

		if (x % l == 0)
		{
			x /= l;
			if (x < -1)
			{
				cout << -1;
				return 0;
			}

			for (int i = 1; i <= l; i++)
			{
				cout << x+i << " ";
			}
			return 0;
		}
		else
		{
			l++;
			continue;
		}
	}
}