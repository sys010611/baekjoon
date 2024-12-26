#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

int cnt[10];

signed main()
{
	memset(cnt, 0, sizeof(cnt));

	int a,b,c;
	cin>>a>>b>>c;
	int ret = a*b*c;

	while (ret > 0)
	{
		cnt[ret%10]++;
		ret /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << cnt[i] << endl;
	}
}
