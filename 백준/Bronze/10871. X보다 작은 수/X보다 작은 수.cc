#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> arr;

	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		int input; cin >> input; arr.push_back(input);
	}
	for (auto item : arr)
	{
		if (item < x) cout << item << " ";
	}
}