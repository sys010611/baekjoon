#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <climits>
#include <cmath>
#include <stack>
using namespace std;

#define MAX 10001
typedef pair<int, int> P;
vector<P> arr;

int p[MAX];

int Find(int n)
{
	if (p[n] == -1)
		return n;
	else
		return p[n] = Find(p[n]);
}
void Merge(int rootA, int rootB) // A를 B에 머지
{
	p[rootA] = rootB;
}

bool compare(P a, P b)
{
	if (a.first != b.first)
	{
		return a.first > b.first;
	}
	else
	{
		return a.second > b.second;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(p, p + MAX, -1);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int p, d;
		cin >> p >> d;
		arr.push_back(P(p, d));
	}

	sort(arr.begin(), arr.end(), compare);

	//for (auto pair : arr)
	//{
	//	cout << pair.first << " " << pair.second << endl;
	//}
	int ret = 0;
	for (auto lecture : arr)
	{
		int price = lecture.first;
		int dueTo = lecture.second;

		int root = Find(dueTo);
		if (root < 1) // 불가능
			continue;
		else
		{
			ret += price;
			Merge(root, root - 1);
		}
	}

	cout << ret;
}
