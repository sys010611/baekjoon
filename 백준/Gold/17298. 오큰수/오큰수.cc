#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

int N;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> S;

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	deque<int> result;

	for (int i = N - 1; i > -1; i--)
	{
		int curr = arr[i];

		while (!S.empty() && S.top() <= curr)
			S.pop();

		if (S.empty())
			result.push_front(-1);
		else
			result.push_front(S.top());

		S.push(curr);
	}

	for(auto item : result)
		cout << item << ' ';
}