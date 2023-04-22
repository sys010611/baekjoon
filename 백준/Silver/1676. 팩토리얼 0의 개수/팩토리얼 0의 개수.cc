#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int count = 0;

	for (int i = n; i >= 5; i--)
	{
		int num = i;
		while (num % 5 == 0)
		{
			num /= 5;
			count++;
		}
	}
	cout << count;
}