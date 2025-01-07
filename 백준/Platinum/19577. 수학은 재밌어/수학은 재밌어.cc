#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
using namespace std;

#define int long long
const int SIZE = 1000001;

vector<bool> isPrime;
vector<int> primes;
vector<int> factors;

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

int EulerPhi(int n)
{
	if (n == 1)
	{
		return 1;
	}

	int result = 1;

	int currPrime;
	int count = 0;
	for (int i = 0; i < primes.size();)
	{
		if (n == 1)
			break;

		currPrime = primes[i];

		if (n % currPrime == 0)
		{
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
		result *= (n - 1);
	}

	return result;
}


void FindFactors(int n)
{
	for (int x = 1; x <= ceil(sqrt(n)); x++)
	{
		if (n % x == 0)
			factors.push_back(x);
	}
	
	int vSize = factors.size();
	for (int i = 0; i<vSize;i++)
	{
		factors.push_back(n / factors[i]);
	}

	sort(factors.begin(), factors.end());
	factors.erase(unique(factors.begin(), factors.end()), factors.end());
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	FindPrimes();

	int N;
	cin >> N;

	FindFactors(N);

	for (auto x : factors)
	{
		if (x * EulerPhi(x) == N)
		{
			cout << x;
			return 0;
		}
	}
	cout << -1;
	return 0;
}