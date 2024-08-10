#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define int long long

int N, K;
vector<int> arr;
map<int, int> prefixSum;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	arr.resize(N);
	for(int i=0;i<N;i++)
		cin >> arr[i];

	prefixSum[0] = 1;

	int sum = 0;
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];

		int target = sum - K;

		if (prefixSum.find(target) != prefixSum.end())
		{
			result += prefixSum[target];
		}

		if (prefixSum.find(sum) == prefixSum.end())
		{
			prefixSum[sum] = 1;
		}
		else
		{
			prefixSum[sum]++;
		}
	}

	cout << result;
}