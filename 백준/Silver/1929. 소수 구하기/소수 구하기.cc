#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int min, MAX;
	cin >> min >> MAX;

	vector<int> prime;
	bool* isPrime = new bool[MAX+1];
	fill(isPrime+2, isPrime+MAX+1, true);
	for (int i = 2; i <= MAX; i++)
	{
		if (isPrime[i])
		{
			prime.push_back(i);
		}
		for (int j = i * 2; j <= MAX; j += i)
		{
			isPrime[j] = false;
		}
	}

	int i = 0;
	while (prime[i] < min)
		i++;

	for (; i < prime.size(); i++)
	{
		cout << prime[i] << "\n";
	}
}