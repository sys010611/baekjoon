#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		int n;
		cin >> n;
		if(n==0)
			break;

		vector<int> prime;
		bool* isPrime = new bool[2*n+1];
		fill(isPrime+2, isPrime + 2*n+1, true);

		for (int i = 2; i <= 2*n; i++)
		{
			if (isPrime[i])
			{
				prime.push_back(i);
			}
			for (int j = i + i; j <= 2 * n; j += i)
			{
				isPrime[j] = false;
			}
		}

	

		int numofPrime = prime.size();

		int i = 0;
		for (; prime[i] <= n; i++)
		{
			numofPrime--;
		}

		cout << numofPrime << endl;
	}
}