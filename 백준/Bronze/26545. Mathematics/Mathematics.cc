#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

signed main()
{
	int ret = 0;

	int n;cin>>n;
	while (n--)
	{
		int input; cin >> input;
		ret += input;
	}

	cout << ret;
}
