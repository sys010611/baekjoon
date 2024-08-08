#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	for (int test = 1; test <= t; test++)
	{
		int n, k;
		cin >> n >> k;

		vector<int> arr;
		arr.resize(n);
		for(int i=0;i<n;i++)
			cin >> arr[i];

		vector<int> LIS;
		LIS.resize(n);
		fill(LIS.begin(), LIS.end(), 0);
		
		vector<int> N; // 길이가 idx인 수열의 마지막에 올수 있는 최솟값
		N.resize(10001);
		fill(N.begin(), N.end(), 1000000000);
		N[0] = 0;
		for (int i = 0; i < n; i++)
		{
			int currNum = arr[i];
			int prevLength = 0; // 이전 날들의 LIS의 길이 중 최대

			// 이분탐색
			auto it = lower_bound(N.begin(), N.end(), currNum) - 1; // 내가 붙을 수 있는 최대 길이 찾기
			prevLength = it - N.begin();

			LIS[i] = prevLength + 1;

			// N 업데이트
			N[LIS[i]] = min(currNum, N[LIS[i]]);
		}

		cout << "Case #" << test << endl;
		if (*max_element(LIS.begin(), LIS.end()) >= k)
			cout << 1 << endl;
		else
			cout << 0 << endl;


		//cout << "Lis: " << endl;
		//for(int i=0;i<n;i++)
		//	printf("%d : %d\n", i, LIS[i]);
	}
}