#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int n;

void Move(int count, int src, int by, int dest)
{
	if (count == 1)
	{
		cout << src << " " << dest << '\n';
		return;
	}

	Move(count-1, src, dest, by);
	Move(1, src, by, dest);
	Move(count-1, by, src, dest);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	cout << (int)pow(2,n) - 1 << endl;
	Move(n, 1, 2, 3);
}