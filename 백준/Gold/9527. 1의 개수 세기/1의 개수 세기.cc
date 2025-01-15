#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
using namespace std;

#define int long long

int A, B;

int pSum[55]; // 최상위비트가 i번 이하인 수들의 1의 개수 누적합

int F(int x)
{
	int result = 0;

	for (int i = 54; i >= 1; i--)
	{
		if ((1LL<<i & x)) // i번 비트가 켜져있다면
		{
			result += pSum[i - 1];
			result += (x - (1LL <<i) + 1);

			x = x & ~(1LL << i);
		}
	}

	if (x > 0)
		result++;

	return result;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;

	pSum[0] = 1;
	for (int i = 1; i < 55; i++)
	{
		pSum[i] = (1LL << i) + pSum[i - 1] + pSum[i - 1];
	}

	//for (int i = 1; i <= 20; i++)
	//{
	//	printf("F(%d) = %d\n", i, F(i));
	//}

	cout << F(B) - F(A - 1);
}