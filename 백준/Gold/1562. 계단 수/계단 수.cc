#include <iostream>
#include <bitset>
using namespace std;

int N;
long long dp[10][101][1<<10];

long long backtrack(int currNum, int currLen, int visited)
{
	if (dp[currNum][currLen][visited] != -1) // 이 상태에서 더 진행하면 얼마나 더 많은 경우의 수가 있는지 이미 알고 있다면
	{
		return dp[currNum][currLen][visited] %= 1000000000;
	}

	// 길이 끝까지 다 채운 경우 (base case)
	if (currLen == N)
	{
		if (visited == ((1<<10) - 1)) // 모든 숫자를 사용했다면
		{
			//cout << "currNum : " << currNum << endl;
			//cout << "currLen : " << currLen << endl;
			//cout << "visited : " << bitset<10>(visited) << endl;

			return dp[currNum][currLen][visited] = 1;
		}
		else // 실패
			return dp[currNum][currLen][visited] = 0;
	}

	// 그렇지 않은 경우 현재 숫자에서 -1, +1해서 더 진행시켜보기
	dp[currNum][currLen][visited] = 0;
	if (currNum < 9)
	{
		dp[currNum][currLen][visited] += backtrack(currNum + 1, currLen + 1, visited | (1 << (currNum + 1))) % 1000000000;
		dp[currNum][currLen][visited] %= 1000000000;
	}
	if (currNum > 0)
	{
		dp[currNum][currLen][visited] += backtrack(currNum - 1, currLen + 1, visited | (1 << (currNum - 1))) % 1000000000;
		dp[currNum][currLen][visited] %= 1000000000;
	}

	return dp[currNum][currLen][visited] %= 1000000000;
}

int main()
{
	cin >> N;

	fill(&dp[0][0][0], &dp[9][100][1 << 10], -1);

	if (N <= 9)
	{
		cout << 0;
		return 0;
	}

	long long result = 0;

	for (int i = 1; i <= 9; i++)
	{
		result += backtrack(i, 1, 1<<i);
		result %= 1000000000;
	}

	cout << result;
}