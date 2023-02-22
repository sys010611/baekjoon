#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m;
vector<vector<int>> result;
vector<int> currArr;
bool visited[8];

void backtrack()
{
	if (currArr.size() == m)
	{
		result.push_back(currArr); //현재 수열 저장
		currArr.pop_back(); //이전 단계로
		return;
	}

	for (int i = 1; i <= n; i++)
	{	
		if (!visited[i])
		{
			currArr.push_back(i);
			visited[i] = true;
			backtrack();
			visited[i] = false;
		}
	}

	if (currArr.size() > 0)
		currArr.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	fill(visited, visited+8, false);
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