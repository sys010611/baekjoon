#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int,int> P;

bool compare(P a, P b)
{
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<P> jewels; // (무게, 가격)
	vector<int> bags;

	int n,k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int m, v;
		cin >> m >> v;
		jewels.push_back(P(m,v));
	}
	for (int i = 0; i < k; i++)
	{
		int c;
		cin >> c;
		bags.push_back(c);
	}

	sort(jewels.begin(), jewels.end(), compare); // 무게 기준 오름차순 정렬
	sort(bags.begin(), bags.end()); // 가방은 작은 순 정렬

	int jewelIdx = 0;

	priority_queue<int> availableJewels;

	long long result = 0;

	for (auto bag : bags)
	{
		while (jewelIdx < jewels.size() && jewels[jewelIdx].first <= bag) // 현재 가방에 넣을 수 있는 보석이라면
		{
			availableJewels.push(jewels[jewelIdx].second); // 우선순위 큐에 그 보석의 가치를 추가
			jewelIdx++;
		}

		// 다 넣은 뒤, 가장 가치가 높은 보석을 하나 챙기기
		if (!availableJewels.empty())
		{
			result += availableJewels.top(); 
			availableJewels.pop();

		}
	}

	cout << result;
}