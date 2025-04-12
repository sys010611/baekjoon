#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define int long long

void draw(int len)
{
	if (len == 1)
	{
		cout << '-';
		return;
	}

	draw(len / 3);
	for (int i = 0; i < len / 3; i++)
		cout << ' ';
	draw(len / 3);
}

signed main()
{
	int N;
	while (cin >> N)
	{
		int len = pow(3, N);
		draw(len);
		cout << endl;
	}
}