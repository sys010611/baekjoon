#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N, H;
vector<int> up;
vector<int> down;
vector<int> result; // 높이 별 충돌 횟수 저장

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> H;
	result.resize(H+1);
	fill(result.begin(), result.end(), 10000000);

	for (int i = 0; i < N; i++)
	{
		int input; cin >> input;
		if (i % 2 == 0)
		{
			down.push_back(input);
		}
		else
		{
			up.push_back(H - input + 1);
		}
	}

	sort(down.begin(), down.end());
	sort(up.begin(), up.end());

	// result 채우기
	for (int currHeight = 1; currHeight <= H; currHeight++)
	{
		int downConflicts;
		int upConflicts;

		downConflicts = down.size() - (lower_bound(down.begin(), down.end(), currHeight) - down.begin());
		upConflicts = (lower_bound(up.begin(), up.end(), currHeight+1) - up.begin());

		result[currHeight] = downConflicts + upConflicts;
	}

	sort(result.begin(), result.end());
	cout << result[0] << " ";

	auto er = equal_range(result.begin(), result.end(), result[0]);
	cout << er.second - er.first;
}