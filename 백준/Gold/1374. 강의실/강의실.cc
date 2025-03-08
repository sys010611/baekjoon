#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

typedef pair<int, int> P;

int N;
vector<P> lectures;

priority_queue<int, vector<int>, greater<int>> PQ;

int ret = 0;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int n, s, e;
		cin >> n >> s >> e;
		lectures.push_back(P(s, e));
	}

	sort(lectures.begin(), lectures.end());

	for (auto l : lectures)
	{
		while (!PQ.empty() && l.first >= PQ.top())
		{
			PQ.pop();
		}
		PQ.push(l.second);

		ret = max(ret, (int)PQ.size());
	}

	cout << ret;
}
