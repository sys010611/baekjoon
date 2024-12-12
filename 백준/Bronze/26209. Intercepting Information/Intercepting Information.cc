#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;


signed main()
{
	bool flag = true;
	for (int i = 0; i < 8; i++)
	{
		int input;
		cin >> input;
		if (input == 9)
		{
			flag = false;
		}
	}

	if (flag)
	{
		cout << "S";
	}
	else
		cout << "F";
}
