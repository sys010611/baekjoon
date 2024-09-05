#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	int count = N/4;

	for (int i = 0; i < count; i++)
	{
		cout << "long ";
	}
	cout << "int";
}