#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int,int>> meetings;

	for (int i = 0; i < n; i++)
	{
		int a,b;
		cin >> a >> b;
		meetings.push_back({a,b});
	}

	sort(meetings.begin(), meetings.end(), compare);

	/*for (int i = 0; i < n; i++)
	{
		cout << meetings[i].first << " " << meetings[i].second << endl;
	}*/

	int idx = 0;
	int endTime = 0;
	int result = 0;
	while (idx < n)
	{
		if (endTime <= meetings[idx].first)
		{
			result++;
			endTime = meetings[idx].second;
		}
		idx++;
	}
	cout << result;
}