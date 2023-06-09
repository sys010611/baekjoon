#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio;
	cin.tie(NULL);

	vector<int>::iterator it;

	int n,m;
	cin >> n >> m;

	vector<int> v;

	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v.push_back(input);
	}

	vector<int> partSum;
	partSum.push_back(0);

	int sum = 0;
	for (it = v.begin(); it != v.end(); it++)
	{
		sum += *it;
		partSum.push_back(sum);
	}

	/*for (it = partSum.begin(); it != partSum.end(); it++)
		cout << *it << " ";*/

	int i, j;
	for (int k = 0; k < m; k++)
	{
		cin >> i >> j;

		cout << partSum[j] - partSum[i-1] << "\n";
	}
}