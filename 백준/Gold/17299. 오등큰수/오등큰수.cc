#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef pair<int,int> P;

int N;
vector<int> arr;
vector<int> result_reversed;
stack<P> S;
int numCount[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	arr.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	// 숫자 별 등장횟수 파악
	fill(numCount, numCount + 1000001, 0);
	for (auto num : arr)
	{
		numCount[num]++;
	}

	for (int i = N - 1; i > -1; i--)
	{
		int currNum = arr[i];
		int currCount = numCount[currNum];

		while(!S.empty() && S.top().second <= currCount)
			S.pop();
		
		if (S.empty())
		{
			result_reversed.push_back(-1);
			//cout << "-1 ";
		}
		else
		{
			result_reversed.push_back(S.top().first);
			//cout << S.top().first << " ";
		}
		S.push(P(currNum, currCount));
	}

	for (auto it = result_reversed.rbegin(); it != result_reversed.rend(); it++)
	{
		cout << *it << " ";
	}
}