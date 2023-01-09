#include <iostream>

using namespace std;

long long dp[91] = { 0, };

long long Fibo(int n)
{
	if (dp[n] != 0)
	{
		return dp[n];
	}

	if (n == 1) //base case
	{
		return 1;
	}

	else if (n == 2) //base case
	{
		return 1;
	}

	else
	{
		return dp[n] = Fibo(n - 1) + Fibo(n - 2); //점화식
	}
}

int main()
{
	dp[1] = 1; //base case
	dp[2] = 1; //base case

	int N;

	cin >> N;

	cout << Fibo(N);
}