#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int e,s,m;
	cin >> e >> s >> m;

	for (int year = 1; ; year++)
	{
		int currE = year%15;
		if(currE == 0)
			currE = 15;

		int currS = year%28;
		if (currS == 0)
			currS = 28;

		int currM = year%19;
		if (currM == 0)
			currM = 19;


		if (e == currE && s == currS && m == currM)
		{
			cout << year;
			return 0;
		}
	}
}