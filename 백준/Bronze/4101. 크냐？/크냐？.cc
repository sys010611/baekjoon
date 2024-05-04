#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (true)
	{
		int a,b;
		cin >> a >> b;
		if(a==0 && b==0)
			return 0;

		if(a>b)	cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}