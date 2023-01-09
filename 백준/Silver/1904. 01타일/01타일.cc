#include <iostream>

using namespace std;

long long dp[1000000];

long long Fibo(int n)
{
	for (int i = 3; i < n+1; i++)
	{
		dp[i] = (dp[i-1] + dp[i-2])%15746;
	}
	return dp[n];
}

int main()
{
	dp[1] = 1; //base case
	dp[2] = 2; //base case

	int N;

	cin >> N;

	cout << Fibo(N);
}