#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m;
vector<vector<int>> result;
vector<int> currArr;
int num[9];
bool visited[10001];

void backtrack()
{
	if (currArr.size() == m)
	{
		result.push_back(currArr);
		currArr.pop_back();
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[num[i]])
		{
			currArr.push_back(num[i]);
			visited[num[i]] = true;
			backtrack();
			visited[num[i]] = false;
		}
	}

	if(!currArr.empty())
		currArr.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	sort(num,num+n);

	backtrack();

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