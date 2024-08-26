#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int dp[501][501];
string str;

bool Check(int s, int e)
{
	return (str[s] == 'a' && str[e] == 't') || (str[s] == 'g' && str[e] == 'c');
}

int DP(int start, int end)
{
	if (dp[start][end] != -1)
	{
		return dp[start][end];
	}

	// base case
	if(start == end)
		return dp[start][end] = 0;
	if (end - start == 1)
	{
		if (Check(start, end))
		{
			//cout << "start : " << start << ", end : " << end << endl;
			//cout << "base case" << endl;
			return dp[start][end] = 2;
		}
		else
			return dp[start][end] = 0;
	}


	int ret = -1;

	// 쪼개보기
	for (int i = start; i <= end - 1; i++)
	{
		int a = DP(start, i);
		int b = DP(i + 1, end);

		ret = max(ret, a + b);
	}

	// 조여보기
	if (Check(start, end))
	{
		//cout << "체크 성공, 조이기" << endl;
		ret = max(ret, DP(start+1, end-1) + 2);
	}

	return dp[start][end] = ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	cin >> str;

	cout << DP(0, str.length()-1);
}