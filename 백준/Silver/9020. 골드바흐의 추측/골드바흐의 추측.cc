#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10000;
bool isPrime[MAX + 1];
vector<int> prime;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(isPrime + 2, isPrime + MAX + 1, true);
	for (int i = 2; i <= MAX; i++)
	{
		if (isPrime[i])
		{
			prime.push_back(i);
		}
		for (int j = i + i; j <= MAX; j += i)
		{
			isPrime[j] = false;
		}
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a,b;

		for (int i = 0; i < prime.size(); i++)
		{
			a = prime[i]; 
			b = n - prime[i];
			if (isPrime[b] && a >= b)
			{
				cout << b << " " << a << endl;
				break;
			}
		}
	}

}