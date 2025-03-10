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

typedef pair<int, int> P;
#define MAX 100000

int N;
int h[MAX];
int cnt_left[MAX]; // 왼쪽으로 보이는 탑의 개수
int cnt_right[MAX]; // 오른쪽으로 보이는 탑의 개수
P num_left[MAX]; // 왼쪽으로 보이는 가장 가까운 탑 <번호, 거리>
P num_right[MAX]; // 오른쪽으로 보이는 가장 가까운 탑 <번호, 거리>

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> h[i];
	}

	// 오른쪽으로 볼 수 있는 탑의 개수 찾기
	stack<P> S; // <건물 번호, 높이>
	for (int i = N - 1; i > -1; i--)
	{
		int currH = h[i]; // 현재 탑 높이
		while (!S.empty() && currH >= S.top().second)
		{
			// currH <= S.top()일 때까지 계속 pop
			S.pop();
		}
		
		cnt_right[i] = S.size();
		if (!S.empty())
		{
			num_right[i] = P(S.top().first, abs(S.top().first - i));
		}
		else
		{
			num_right[i] = P(MAX + 1, MAX + 1);
		}
		S.push(P(i, currH));
	}

	// 왼쪽으로 볼 수 있는 탑의 개수 찾기
	S = stack<P>();
	for (int i = 0; i < N; i++)
	{
		int currH = h[i]; // 현재 탑 높이
		while (!S.empty() && currH >= S.top().second)
		{
			// currH <= S.top()일 때까지 계속 pop
			S.pop();
		}

		cnt_left[i] = S.size();
		if (!S.empty())
		{
			num_left[i] = P(S.top().first, abs(S.top().first - i));
		}
		else
		{
			num_left[i] = P(MAX + 1, MAX + 1);
		}
		S.push(P(i, currH));
	}

	for (int i = 0; i < N; i++)
	{
		cout << cnt_left[i] + cnt_right[i] << " ";

		if (cnt_left[i] + cnt_right[i] == 0)
		{
			cout << '\n';
			continue;
		}

		// 가장 가까운 건물의 번호 중 작은 번호로 출력
		if (num_left[i].second == num_right[i].second) // 양 쪽 탑의 거리가 같을 경우 작은 번호로
		{
			cout << min(num_left[i].first, num_right[i].first) + 1 << endl; // +1 : 범위 조정
		}
		else
		{
			if (num_left[i].second < num_right[i].second) // 왼쪽 탑이 더 가까울 경우
			{
				cout << num_left[i].first + 1 << '\n';
			}
			else // 오른쪽 탑이 더 가까울 경우
			{
				cout << num_right[i].first + 1 << '\n';
			}
		}
	}
}
