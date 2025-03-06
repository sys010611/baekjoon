#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

#define int long long

#define MAX 1000001

vector<int> primeExp;
vector<int> primes;
bool isPrime[MAX];
int f[MAX];
int prefixSumF[MAX];

void FindPrimes()
{
	fill(isPrime, isPrime + MAX, true);
	isPrime[0] = false; isPrime[1] = false;
	for (int i = 2; i < MAX; i++)
	{
		if (isPrime[i]) primes.push_back(i);
		for (int j = i + i; j < sqrt(MAX) + 1; j += i)
			isPrime[j] = false;
	}

	primeExp.resize(primes.size());
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(f, f + MAX, 1);


	for (int i = 2; i < MAX; i++)
	{
		for (int j = 1; j < 500001; j++)
		{
			if (i * j >= MAX)
				break;
			f[i * j] += i;
		}
	}
	

	//for (int i = 1; i <= 10; i++)
	//{
	//	printf("f[%d] : %d\n", i, f[i]);
	//}

	prefixSumF[1] = f[1];
	for (int i = 2; i < MAX; i++)
	{
		prefixSumF[i] = prefixSumF[i - 1] + f[i];
	}

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;

		cout << prefixSumF[N] << '\n';
	}
}
