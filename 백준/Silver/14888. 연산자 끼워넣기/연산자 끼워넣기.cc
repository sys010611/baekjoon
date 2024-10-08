#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define int long long

vector<int> A;
int N;


int maxRet = -2000000000;
int minRet = 2000000000;

void Backtrack(int currIdx, int prevNum, int plus, int minus, int mul, int div)
{
	if (currIdx == N)
	{
		maxRet = max(maxRet, prevNum);
		minRet = min(minRet, prevNum);

		return;
	}

	int currNum = A[currIdx];
	if (plus > 0)
	{
		Backtrack(currIdx + 1, prevNum + currNum, plus - 1, minus, mul, div);
	}
	if (minus > 0)
	{
		Backtrack(currIdx + 1, prevNum - currNum, plus, minus - 1, mul, div);
	}
	if (mul > 0)
	{
		Backtrack(currIdx + 1, prevNum * currNum, plus, minus, mul - 1, div);
	}
	if (div > 0)
	{
		Backtrack(currIdx + 1, prevNum / currNum, plus, minus, mul, div - 1);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int plusCount;
	int minusCount;
	int mulCount;
	int divCount;

	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> plusCount >> minusCount >> mulCount >> divCount;

	Backtrack(1, A[0], plusCount, minusCount, mulCount, divCount);

	cout << maxRet << endl;
	cout << minRet;
}