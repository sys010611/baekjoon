#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define DIV 1000000000
#define int long long

int N;
int dp[101][10];

int GetCount(int currLen, int prevNum)
{
	if(dp[currLen][prevNum] != -1)
		return dp[currLen][prevNum];
	
	if(currLen == N) // base case
		return dp[currLen][prevNum] = 1;

	int ret = 0;
	if(prevNum <= 8)
		ret += GetCount(currLen + 1, prevNum + 1) % DIV;
	if(prevNum >= 1)
		ret += GetCount(currLen + 1, prevNum - 1) % DIV;
	return dp[currLen][prevNum] = ret % DIV;
}

signed main()
{
	cin >> N;
	memset(dp, -1, sizeof(dp));

	int ret = 0;
	for (int i = 1; i < 10; i++)
	{
		ret += GetCount(1, i) % DIV;
	}
	cout << ret % DIV;

}