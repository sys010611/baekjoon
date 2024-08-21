#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int,int> P;
vector<P> connections;
vector<int> arr;

int dp[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a,b;
		cin>> a>>b;
		connections.push_back({a,b});
	}

	sort(connections.begin(), connections.end());

	for (auto& item : connections)
	{
		arr.push_back(item.second);
	}

	//for (auto item : arr)
	//{
	//	cout << item << " ";
	//}
	//cout << endl;

	// base case
	fill(dp, dp + 100, 1);

	// arr에서 LIS 구하기
	for (int i = 0; i < arr.size(); i++)
	{
		int curr = arr[i];

		for (int j = 0; j < i; j++)
		{
			int prev = arr[j];
			if (prev < curr)
			{
				int length = dp[j] + 1;
				dp[i] = max(dp[i], length);
			}
		}
	}

	//for (int i = 0; i < arr.size(); i++)
	//{
	//	printf("i: %d, dp[i] : %d\n", i, dp[i]);
	//}
	//cout << "LIS 길이: " << *max_element(dp, dp+n) << endl;

	cout << n - *max_element(dp, dp + n);
}