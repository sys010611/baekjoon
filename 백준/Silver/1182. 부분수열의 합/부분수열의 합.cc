#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num[20];
int currSum = 0;
int result = 0;
int n, s;

void backtrack(int currIndex);

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	backtrack(0);
	cout << result;
}

void backtrack(int currIndex)
{
	if (currIndex == n)
		return;

	if (currSum + num[currIndex] == s)
		result++;

	backtrack(currIndex+1);

	currSum += num[currIndex];
	backtrack(currIndex+1);

	currSum -= num[currIndex];
}