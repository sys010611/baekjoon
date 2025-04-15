#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n; cin >> n;
	int a=0, b=0, c = 0;

	for (int i = 1; i <= n; i++)
	{
		a += i;
		//b += i*i;
		c += i * i * i;
	}

	cout << a << endl << a*a << endl << c;
}