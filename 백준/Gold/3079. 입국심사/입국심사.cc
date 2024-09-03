#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define int unsigned long long

int N, M;
vector<int> T;

bool Check(int time)
{
	int doneCount = 0; // 처리 완료한 사람 수

	for (int i = 0; i < N; i++)
	{
		doneCount += time / T[i];

		if (doneCount >= M)
			return true;
	}

	return false;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	T.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> T[i];
	}
	sort(T.begin(), T.end());

	// 이분탐색
	int low = 1;
	int high = 1e19;

	if (Check(low))
	{
		cout << low;
		return 0;
	}

	while (low + 1 < high)
	{
		int mid = (low+high)/2;
		//cout << "mid : " << mid << endl;


		if (Check(low) == Check(mid))
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}

	cout << high;
}