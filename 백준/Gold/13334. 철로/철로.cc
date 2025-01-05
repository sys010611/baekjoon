#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int n, d;
vector<P> lines;

bool compare(P& a, P& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	
	return a.second < b.second;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int result = 0;

	cin >> n;
	lines.resize(n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);

		lines[i] = P(a, b);
	}

	cin >> d;

	sort(lines.begin(), lines.end(), compare);

	priority_queue<int, vector<int>, greater<int>> PQ;

	int knownEnd = -100000001;

	for (P currLine : lines)
	{
		int s = currLine.first;
		int e = currLine.second;

		PQ.push(s);


		while (!PQ.empty() && e - PQ.top() > d)
			PQ.pop();

		result = max(result, (int)PQ.size());
	}

	cout << result;
}

