#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
vector<vector<int>> result;
vector<int> currArr;
int num[8];
int visited[8];
int lastNum;

void backtrack(int index)
{
	if (currArr.size() == m)
	{
		result.push_back(currArr); //현재 수열 저장
		lastNum = currArr.back();
		currArr.pop_back(); //이전 단계로
		return;
	}

	lastNum = -1;
	for (int i = index; i < n; i++)
	{
		if (lastNum != num[i])
		{
			//visited[i] = true;
			currArr.push_back(num[i]);
			backtrack(i);
			//visited[i] = false;
		}
	}

	if (currArr.size() > 0)
	{
		lastNum = currArr.back();
		currArr.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) 
		cin >> num[i];

	sort(num, num + n);
	fill(visited, visited + 8, false);

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