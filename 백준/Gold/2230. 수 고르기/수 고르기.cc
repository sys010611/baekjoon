#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <climits>
#include <cmath>
#include <stack>
using namespace std;

#define int long long

int N, M;
int A[100001];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A, A + N);

	int s = 0;
	int e = 0;

	int minDiff = 1e11;

	while (s<=e && e < N)
	{
		int currDiff = abs(A[e] - A[s]);
		if (currDiff < M) // 조건 불만족
		{
			e++;
			continue;
		}
		else // 조건 만족
		{
			minDiff = min(minDiff, currDiff);
			s++;
			continue;
		}
	}

	cout << minDiff;
}
