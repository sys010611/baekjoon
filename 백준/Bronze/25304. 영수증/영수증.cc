#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define int long long

int arr[100];

signed main()
{
	int x;
	int n;
	cin >>x>>n;
	int sum =0;
	for (int i = 0; i < n; i++)
	{
		int a,b;
		cin >> a >> b;
		sum += a*b;
	}
	if (x == sum)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}