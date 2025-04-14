#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int s, f;
	cin >> s >> f;

	if (f < s)
	{
		cout << "flight";
	}
	else
	{
		cout << "high speed rail";
	}
}