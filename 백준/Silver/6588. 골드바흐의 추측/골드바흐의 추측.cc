#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
bool isPrime[MAX + 1];
vector<int> prime;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(isPrime+2, isPrime+MAX+1, true);
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

	while (true)
	{
		int n;
		cin >> n;
		if(n == 0) break;

		bool found = false;

		for (int i = 0; i < prime.size(); i++)
		{
			if (isPrime[n-prime[i]])
			{
				found = true;
				cout << n << " = " << prime[i] << " + " << n-prime[i] << "\n";
				break;
			}
		}
		if(!found) cout << "Goldbach's conjecture is wrong." << "\n";
	}
	
}