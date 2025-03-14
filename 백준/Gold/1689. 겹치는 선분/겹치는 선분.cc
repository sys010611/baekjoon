#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <climits>
#include <cmath>
#include <stack>
using namespace std;
#define int long long

typedef pair<int, int> P;
vector<P> arr;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int s, e; cin >> s >> e;
		arr.push_back(P(s, e));
	}

	sort(arr.begin(), arr.end());

	priority_queue<int, vector<int>, greater<int>> PQ;
	int ret = -1;

	for (auto line : arr)
	{
		int left = line.first;
		int right = line.second;

		while (!PQ.empty() && left >= PQ.top())
		{
			PQ.pop();
		}

		PQ.push(right);
		ret = max(ret, (int)PQ.size());
	}

	cout << ret;
}
