#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

signed main()
{
	int ans;cin>>ans; int ret = 0;
	for (int i = 0; i < 5; i++)
	{
		int input; cin >> input;
		if(input == ans)ret++;
	}
	cout << ret;
}
