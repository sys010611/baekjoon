#include <iostream>

using namespace std;

int Minimum(int a, int b, int c)
{
	int smallest = a;
	if (smallest > b)
		smallest = b;
	if (smallest > c)
		smallest = c;
	return smallest;
}

int main()
{
	int X;
	cin >> X;

	int dp[1000001]; //숫자 당 필요한 연산 횟수를 저장하는 배열
	for (int i = 0; i < X + 1; i++)
	{
		dp[i] = 0;
	}
	dp[1] = 0; //1을 1로 만드는데는 0회
	dp[2] = 1; //2를 1로 만드는데는 1회
	dp[3] = 1; //3을 1로 만드는데는 1회


	for (int i = 4; i < X + 1; i++)
	{
		if (i % 3 == 0 && i % 2 == 0) // 3으로 나누어떨어짐, 2로 나누어떨어짐
		{
			int minus1 = dp[i - 1];
			int division3 = dp[i / 3];
			int division2 = dp[i / 2];

			dp[i] = Minimum(minus1, division3, division2) + 1; //처음 한번의 계산 -> +1
		}

		else if (i % 3 == 0) // 3으로만 나누어떨어짐
		{
			int minus1 = dp[i - 1];
			int division3 = dp[i / 3];
			dp[i] = min(minus1, division3) + 1;
		}
		else if (i % 2 == 0) // 2로만 나누어떨어짐
		{
			int minus1 = dp[i - 1];
			int division2 = dp[i / 2];
			dp[i] = min(minus1, division2) + 1;
		}
		else
		{
			dp[i] = dp[i-1] + 1;
		}
		
	}

	std::cout << dp[X];

	return 0;
}