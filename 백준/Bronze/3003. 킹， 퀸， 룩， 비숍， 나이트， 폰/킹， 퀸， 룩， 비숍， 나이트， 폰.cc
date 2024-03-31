#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


int main()
{
	ios::sync_with_stdio();
	cin.tie();

	int ans[6] = {1,1,2,2,2,8};
	int curr[6];

	for(int i=0;i<6;i++)
		cin >> curr[i];

	for (int i = 0; i < 6; i++)
	{
		cout << ans[i] - curr[i] << " ";
	}
}
