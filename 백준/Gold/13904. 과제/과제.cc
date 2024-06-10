#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

int N;
int p[1001];

int find(int n)
{
	if (p[n] == -1)
		return n;
	else
		return find(p[n]);
}

// b를 a에 붙인다.
void merge(int rootA, int rootB)
{
	
	p[rootB] = rootA;
}

bool compare(P a, P b)
{
	return a.second > b.second;
}

int main()
{
	fill(p, p+1001, -1);

	vector<P> homeworks;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int d, w;
		cin >> d >> w;
		homeworks.push_back(P(d, w));
	}

	sort(homeworks.begin(), homeworks.end(), compare);

	int result = 0;

	for (auto& item : homeworks)
	{
		int d = item.first;
		int w = item.second;

		int targetDay = find(d);

		if (targetDay > 0) // 0번째 날이다 = 불가능하다
		{
			result += w;

			int mergingDay = find(targetDay-1);
			// targetDay는 소모, 앞의 가능한 날로 merge
			merge(mergingDay,targetDay);
		}
		else
			continue;
	}

	cout << result;
}