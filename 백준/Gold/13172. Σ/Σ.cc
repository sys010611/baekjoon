#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#include <numeric>
using namespace std;

#define MOD 1000000007
#define int unsigned long long

int M;
int S[10000];
int N[10000];

int Pow(int a, int b)
{
	if (b == 1)
	{
		return a;
	}

	if (b % 2 == 0)
	{
		int ret = Pow(a, b / 2);
		return ret * ret % MOD;
	}
	else
	{
		int ret = Pow(a, b / 2);
		return ret * ret % MOD * a % MOD;
	}
}

signed main()
{
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> N[i] >> S[i];
	}

	int result = 0;
	for (int i = 0; i < M; i++)
	{
		int a = S[i];
		int b = N[i];


		//if (a % b == 0)
		//{
		//	result += a / b;
		//	continue;
		//}
		
		// gcd로 기약분수 만들기
		int g = gcd(a, b);
		a /= g;
		b /= g;

		//cout << "a : " << a << endl;
		//cout << "b : " << b << endl;

		// 문제 조건대로 계산
		int _b = Pow(b, MOD - 2) % MOD;
		//cout << "b^-1 : " << _b << endl;

		int ret = a * _b % MOD;
		result = (result % MOD + ret % MOD) % MOD;
	}
	cout << result;
}
