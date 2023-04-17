#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1299709;
bool isPrime[MAX + 1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(isPrime+2, isPrime+MAX+1, true);
	for (int i = 2; i <= MAX; i++)
	{
		for (int j = i + i; j <= MAX; j += i)
		{
			isPrime[j] = false;
		}
	}

	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;

		if (isPrime[k])
		{
			cout << 0 << "\n";
			continue;
		}	

		int start , end;

		for (int i = k+1; i <= MAX; i++)
		{
			if (isPrime[i])
			{
				end = i;
				break;
			}
		}
		for (int i = k - 1; i >= 2; i--)
		{
			if (isPrime[i])
			{
				start = i;
				break;
			}
		}

		cout << end - start << "\n";
	}
}