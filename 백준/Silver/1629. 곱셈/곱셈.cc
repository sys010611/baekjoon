#include <iostream>
using namespace std;

long long A, B, C;

long long power(int c, int n)
{
	if (n == 1)
	{
		return c % C;
	}

	long long x = power(c, n/2) % C;
	if (n % 2 == 0)
	{
		return (x * x) % C;
	}
	else
	{
		return ((x * x) % C * c) % C;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B >> C;
	
	cout << power(A,B) % C;
}