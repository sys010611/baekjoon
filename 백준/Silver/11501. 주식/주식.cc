#include <iostream>
#include <queue>
#include <string>
#include <bitset>
using namespace std;

int arr[1000000];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		long long result = 0;

		int high = arr[n-1]; // 마지막 날 주가를 고점으로 가정하고 시작

		for (int i = n - 2; i >= 0; i--)
		{
			if (arr[i] < high)
			{
				result += high - arr[i];
			}
			else if (arr[i] > high) // 더 높은 고점이 나타났을 시 업데이트
			{
				high =  arr[i];
			}
		}

		cout << result << endl;
	}
}


