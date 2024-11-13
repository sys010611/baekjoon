#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>> n;
	int target = 1000-n;

	int result = 0;

	while (target >= 500)
	{
		target-=500;
		result++;
	}
	while (target >= 100)
	{
		target -= 100;
		result++;
	}
	while (target >= 50)
	{
		target -= 50;
		result++;
	}
	while (target >= 10)
	{
		target -= 10;
		result++;
	}
	while (target >= 5)
	{
		target -= 5;
		result++;
	}
	while (target >= 1)
	{
		target -= 1;
		result++;
	}

	cout << result;
}
