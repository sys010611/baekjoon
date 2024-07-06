#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, T;
vector<pair<int,int>> chapters; //<공부 시간, 배점>
int dp[100][10001]; // <단원, 남은 시간>일 때 최대 점수

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> T;
	
	for (int i = 0; i < N; i++)
	{
		int time, score;
		cin >> time >> score;
		chapters.push_back({time, score});
	}

	// base case
	for (int i = 0; i < 100; i++)
	{
		dp[i][0] = 0;
	}
	for (int time = 1; time <= T; time++)
	{
		if (time >= chapters[0].first)
			dp[0][time] = chapters[0].second;
		else
			dp[0][time] = 0;
	}

	for (int i=1;i<chapters.size();i++)
	{
		auto& item = chapters[i];

		int neededTime = item.first;
		int givingScore = item.second;

		for (int givenTime = 1; givenTime <= T; givenTime++)
		{
			if (givenTime < neededTime)
			{
				dp[i][givenTime] = dp[i-1][givenTime];
			}
			else
			{
				dp[i][givenTime] = max(dp[i - 1][givenTime], dp[i-1][givenTime - neededTime] + givingScore);
			}
		}
	}

	cout << dp[N-1][T];
}