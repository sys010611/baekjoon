#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
#define MOD % 10007

int N;
int dpC[53][53];
int dpF[53][53];

int C(int n, int r)
{
	if (dpC[n][r] != -1)
		return dpC[n][r];

	if (n == r || r == 0)
	{
		return dpC[n][r] = 1;
	}
	return dpC[n][r] = C(n - 1, r - 1) + C(n - 1, r);
}

// n장 중 k장을 포카드 없이 뽑는 경우의 수
int F(int n, int k)
{
	//printf("F(%d, %d)\n", n, k);
	if (dpF[n][k] != -1)
		return dpF[n][k];

	if (k < 4)
	{
		return dpF[n][k] = C(n, k);
	}

	int total = C(n, k);
	//cout << "전체 경우의 수 : " << total<< endl;

	int includingFourCard = 0;

	int maxPairCount = k / 4;
	for (int i = 1; i <= maxPairCount; i++)
	{
		// 포카드가 i쌍 존재하도록 하는 경우의 수
		includingFourCard += C(n/4, i) * F(n - i * 4, k - i * 4);
	}
	//cout << "포카드 포함 경우의 수 : " << includingFourCard << endl;

	return dpF[n][k] = total - includingFourCard;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dpC, -1, sizeof(dpC));
	memset(dpF, -1, sizeof(dpF));

	cin >> N;

	int maxPairCount = N / 4;
	int includingFourCard = 0;
	for (int i = 1; i <= maxPairCount; i++)
	{
		int a = C(13, i) * F(52 - i * 4, N - i * 4);
		//cout << "i : " << i << endl;
		//cout << "경우의수 : " << a << endl;
		// 포카드가 i쌍 존재
		includingFourCard += a;
	}

	cout << includingFourCard MOD;
}
