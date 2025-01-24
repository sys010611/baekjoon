#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> prefixSum; // 1, 2, 3, 4 ... 를 누적합

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int X;
	cin >> X;

	if (X == 1)
	{
		cout << "1/1";
		return 0;
	}

	int curr = 0;
	for (int i = 1;; i++)
	{
		curr += i;
		if (curr > 10000000)
			break;

		prefixSum.push_back(curr);
	}

	//for (auto item : prefixSum)
	//	cout << item << " ";

	auto lb = lower_bound(prefixSum.begin(), prefixSum.end(), X);
	int idx = lb - prefixSum.begin(); 

	int group = idx + 1;
	int idxInGroup = X - prefixSum[idx - 1];

	//printf("%d는 %d번째 그룹의 %d번째 수\n", X, group, idxInGroup);

	int num, denom;
	if (group % 2 == 0)
	{
		num = idxInGroup;
		denom = group + 1 - num;
	}
	else
	{
		denom = idxInGroup;
		num = group + 1 - denom;
	}

	cout << num << "/" << denom;
}
