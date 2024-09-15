#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	if (n%7 == 2)
		cout << 1;
	else
		cout << 0;
}