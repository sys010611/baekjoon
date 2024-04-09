#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}

	int maxH = 0;
	int result = 0;

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		int curr = arr[i];
		if (curr > maxH)
		{
			maxH = curr;
			result++;
		}
	}

	cout << result;
}