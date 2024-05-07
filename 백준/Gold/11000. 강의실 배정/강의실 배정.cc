#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

int N;
vector<pair<int,int>> classes;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int s,t;
		cin >> s >> t;
		classes.push_back({s,t});
	}

	sort(classes.begin(), classes.end(), compare);

	priority_queue<int, vector<int>, greater<int>> finishingTimes;
	finishingTimes.push(0);

	int result = 1;
	for (auto item : classes)
	{
		int minFinishingTime = finishingTimes.top(); 
		if (minFinishingTime <= item.first) // 강의실을 이어서 쓸 수 있을 경우
		{
			finishingTimes.pop();
			finishingTimes.push(item.second);
		}
		else
		{
			result++;
			finishingTimes.push(item.second);
		}
	}

	cout << result;
}