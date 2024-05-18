#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	for (auto item : arr) cout << item << endl;
}