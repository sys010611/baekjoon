#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <assert.h>
#include <climits>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr;
	for (int i = 1; i <= N; i++)
	{
		arr.push_back(i);
	}

	do
	{
		for (auto item : arr)
			cout << item << " ";
		cout << '\n';
	}
	while (next_permutation(arr.begin(), arr.end()));
}