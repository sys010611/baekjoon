#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

#define int unsigned long long
const int SIZE = 1000001;

vector<bool> isPrime;
vector<int> primes;

void FindPrimes()
{
	isPrime.resize(SIZE, true);

	for (int i = 2; i < SIZE; i++)
	{
		if (isPrime[i])
			primes.push_back(i);
		else
			continue;

		for (int j = i * 2; j < SIZE; j += i)
		{
			isPrime[j] = false;
		}
	}
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	FindPrimes();

	while (true)
	{
		int n;

		cin >> n;
		if (n == 0)
			return 0;
		else if (n == 1)
		{
			cout << 0 << endl;
			continue;
		}

		int result = 1;

		set<int> debug_usedPrimes;
		int currPrime;
		int count = 0;
		for (int i = 0; i < primes.size();)
		{
			if (n == 1)
				break;

			currPrime = primes[i];

			if (n % currPrime == 0)
			{
				debug_usedPrimes.insert(currPrime);
				n /= currPrime;
				count++;
				continue;
			}
			else
			{
				if (count > 0)
				{
					result *= pow(currPrime, count) - pow(currPrime, count - 1);
				}

				count = 0;
				i++;
			}
		}
		if (count > 0)
		{
			result *= pow(currPrime, count) - pow(currPrime, count - 1);
		}

		if (n != 1)
		{
			debug_usedPrimes.insert(n);
			result *= (n - 1);
		}
		//for (auto item : debug_usedPrimes)
		//	cout << item << " ";
		//cout << endl;

		cout << result << endl;
	}
}