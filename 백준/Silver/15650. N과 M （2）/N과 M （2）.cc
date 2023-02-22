#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m;
vector<vector<int>> result;
vector<int> currArr;

void backtrack(int prevNum)
{
	if (currArr.size() == m)
	{
		result.push_back(currArr);
		currArr.pop_back();
		return;
	}

	for (int i = prevNum + 1; i <= n; i++)
	{
		currArr.push_back(i);
		backtrack(i);
	}

	if(!currArr.empty())
		currArr.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	backtrack(0);

	vector<vector<int>>::iterator it;
	vector<int>::iterator it2;

	for (it = result.begin(); it != result.end(); it++)
	{
		vector<int> currLine = *it;
		for (it2 = currLine.begin(); it2 != currLine.end(); it2++)
		{
			cout << *it2 << " ";
		}
		cout << "\n";
	}
}