#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> P;

vector<P> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int a,b;
		cin >> a >> b;
		if(a > b)
			arr.push_back(make_pair(a,b));
	}

	sort(arr.begin(), arr.end(), greater<pair<int,int>>());

	/*for (auto it = arr.begin(); it != arr.end(); it++)
		cout << it->first << " " << it->second << endl;*/

	unsigned long long result = m; // 기본적으로 정방향은 모두 거리에 포함

	P curr = arr[0];
	for (auto it = arr.begin() + 1; it != arr.end(); it++)
	{
		int a = it->first;
		int b = it->second;
		//현재 구간에 완전히 들어오는 경우
		if (curr.second <= b)
		{
			continue;
		}
		//현재 구간에서 왼쪽으로 확장되는 경우
		if (curr.second <= a && b < curr.second)
		{
			curr.second = b;
			continue;
		}

		// 현재 구간에서 아예 벗어나는 경우
		if (a < curr.second)
		{
			result += (2 * (curr.first - curr.second));
			curr = P(a,b);
			continue;
		}
	}

	result += (2 * (curr.first - curr.second));
	cout << result;
}