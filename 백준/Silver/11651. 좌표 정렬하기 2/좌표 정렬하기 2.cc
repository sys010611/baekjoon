#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> P;
vector<P> vec;

bool compare(P& a, P& b)
{
	if(a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		vec.push_back({ x, y });
	}

	sort(vec.begin(), vec.end(), compare);

	for (auto& item : vec)
	{
		cout << item.first << " " << item.second << '\n';
	}
}