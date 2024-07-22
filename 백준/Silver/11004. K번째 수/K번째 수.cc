#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	vector<int> vec;
	vec.resize(n);
	for(int i=0;i<n;i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());
	cout << vec[k-1];
}