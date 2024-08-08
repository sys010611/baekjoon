#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	for (int test = 1; test <= t; test++)
	{
		int n, k;
		cin >> n >> k;

		vector<int> arr;
		arr.resize(n);
		for(int i=0;i<n;i++)
			cin >> arr[i];

		vector<int> LIS;
		LIS.resize(n);
		fill(LIS.begin(), LIS.end(), 0);
		
		for (int i = 0; i < n; i++)
		{
			int prev = 0; // 이전 날까지 중 LIS의 길이
			for (int j = 0; j < i; j++)
			{
				if (arr[j] < arr[i])
				{
					prev = max(prev, LIS[j]);
				}
			}
			LIS[i] = prev + 1;
		}

		cout << "Case #" << test << endl;
		if (*max_element(LIS.begin(), LIS.end()) >= k)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}