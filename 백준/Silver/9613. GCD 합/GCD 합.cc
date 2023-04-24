#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	if (a == b)
		return a;
	else if (a < b)
		swap(a,b);

	int r;
	do
	{
		r = a%b;
		a=b;
		b=r;
	}
	while(r != 0);

	return a;
}

int arr[100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		long long result = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				result += gcd(arr[i], arr[j]);
			}
		}

		cout << result << endl;
	}
}