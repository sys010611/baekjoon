#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int N;
vector<pair<int,int>> towers; // 높이, idx

int main()
{
	cin >> N;
	towers.resize(N);
	for (int i = 0; i < N; i++)
	{
		int height;
		cin >> height;
		towers[i] = {height, i+1};
	}

	stack<pair<int,int>> S;

	for (auto& curr : towers)
	{
		int height = curr.first;
		int idx = curr.second;

		while (!S.empty() && S.top().first < height)
		{
			S.pop();
		}

		if (S.empty())
		{
			cout<<0<<" ";
		}
		else
		{
			cout << S.top().second << " ";
		}

		S.push(curr);
	}
}