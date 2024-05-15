#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	if(n == 100)
		cout << 'A';
	else
	{
		switch (n / 10)
		{
			case 9:
				cout << 'A';
				break;
			case 8:
				cout << 'B';
				break;
			case 7:
				cout << 'C';
				break;
			case 6:
				cout << 'D';
				break;
			default:
				cout << 'F';
				break;

		}
	}
}