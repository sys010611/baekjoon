#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

int price[11];

signed main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin >> price[i];

	int m;
	cin >> m;
	int answer = 0;
	while (m--)
	{
		int num;cin>>num;
		num--;
		answer += price[num];
		//cout << price[num] << endl;
	}
	cout << answer;
}
