#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1000000000

int dp[501][501]; // [n][m] : n부터 m까지 합치는 최소비용
int sum[501];
vector<int> chapters;

int GetMin(int start, int end)
{
	if (dp[start][end] != INF)
		return dp[start][end];

	if(start+1 == end)
		return dp[start][end] = chapters[start] + chapters[end];

	int result = INF;
	for (int i = start; i <= end - 1; i++) // 쪼개는 구간을 계속 바꿔가면서 최소비용 찾기
	{
		int newResult = GetMin(start, i) + GetMin(i + 1, end) + sum[end] - sum[start-1];

		result = min(result, newResult);
	}

	return dp[start][end] = result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		fill(&dp[0][0], &dp[500][501], INF);
		fill(sum, sum+501, 0);

		int k;
		cin >> k;
		
		chapters.resize(k+1);

		for (int i = 1; i <= k; i++)
		{
			cin >> chapters[i];
		}

		int currSum = 0;
		for (int i = 1; i <= k; i++)
		{
			currSum += chapters[i];
			sum[i] = currSum;
		}

		//for(auto item:chapters) cout << item << " ";
		//cout << endl;
		//for(int i=0;i<=k;i++)	cout << sum[i] << " ";
		//cout << endl;

		// base case
		for (int i = 0; i <= k; i++)
		{
			dp[i][i] = 0;
		}

		cout << GetMin(1, k) << endl;
	}
}