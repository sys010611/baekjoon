#include <iostream>
#include <queue>
#include <unordered_set>
#include <cstring>
using namespace std;

signed main()
{
	while (true)
	{
		int n;
		cin >> n;

		if (n == 0)
			return 0;

		int ret = 0;
		while (n > 0)
		{
			ret += n;
			n--;
		}
		cout << ret << endl;
	}
	
}
