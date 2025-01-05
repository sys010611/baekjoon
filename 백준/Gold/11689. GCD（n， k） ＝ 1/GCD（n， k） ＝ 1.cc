#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

#define int unsigned long long
#define SIZE 1000001

int n;
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
	//for (auto item : primes)
	//	cout << item << " ";
	//cout << endl;
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int result = 1;

	cin >> n;

	FindPrimes();

	set<int> debug_usedPrimes;
	int currPrime;
	int count = 0;
	for (int i = 0; i < primes.size();)
	{
		//cout << "n : " << n << endl;

		currPrime = primes[i];
		if (n == 1)
			break;
		//cout << "currPrime : " << currPrime << endl;

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
				//printf("%d를 %d번 사용\n", currPrime, count);
				result *= pow(currPrime, count) - pow(currPrime, count - 1);
				//cout << "result 갱신 : " << result << endl;;
			}

			count = 0;
			i++;
		}
	}
	if (count > 0)
	{
		//printf("%d를 %d번 사용\n", currPrime, count);
		result *= pow(currPrime, count) - pow(currPrime, count - 1);
		//cout << "result 갱신 : " << result << endl;;
	}


	if (n != 1)
	{
		debug_usedPrimes.insert(n);
		result *= (n - 1);
	}
	


	//for (auto item : debug_usedPrimes)
	//	cout << item << " ";
	//cout << endl;

	cout << result;
}