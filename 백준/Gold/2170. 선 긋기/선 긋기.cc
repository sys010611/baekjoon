#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int>> v;

int result = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int x,y;
	while (n--)
	{
		cin >> x >> y;

		v.push_back(make_pair(x,y));
	}

	sort(v.begin(), v.end());

	pair<int, int> curr = make_pair(v[0].first, v[0].second);

	for (auto it = v.begin()+1; it != v.end(); it++)
	{
		int x = it->first;
		int y = it->second;
		
		if (y <= curr.second) //현재 구간에 들어올 경우
		{
			// 변화 없음
		}
		else if (x <= curr.second && y > curr.second) // 현재 구간에서 오른쪽으로 확장되는 경우
		{
			curr.second = y;
		}
		else if (x > curr.second) // 현재 구간을 넘어 시작하는 경우
		{
			result += (curr.second - curr.first);
			curr = make_pair(x,y);
		}
	}

	//마지막 curr의 길이도 result에 더해줌
	result += curr.second - curr.first;
	cout << result;
}


