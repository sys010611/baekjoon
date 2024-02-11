#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> coins;

	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		coins.push_back(input);
	}

	sort(coins.begin(), coins.end(), greater<int>());

	//for (auto it = coins.begin(); it != coins.end(); it++)
	//{
	//	cout << *it << endl;
	//}

	int usedCoinCount = 0;

	for (auto it = coins.begin(); it != coins.end(); it++)
	{
		int value = *it;

		if (value <= K)
		{
			usedCoinCount += K / value;
			K = K % value;
		}

		if(K == 0) break;
	}

	cout << usedCoinCount;
}