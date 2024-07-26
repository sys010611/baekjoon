#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

#define int unsigned long long

signed main()
{
	int S; cin >> S;

	int sum = 0;


	int count = 0;
	int lastNum = 0;
	int lastNum2 = 0;

	for (int i = 1;;)
	{
		sum += i;
		count++;
		lastNum2 = lastNum;
		lastNum = i;

		if (sum == S)
		{
			break;
		}
		else if(sum > S)
		{
			count -= 2;

			sum -= lastNum;
			sum -= lastNum2;

			i = lastNum;
		}
		else
		{
			i++;
		}
	}

	cout << count;
}