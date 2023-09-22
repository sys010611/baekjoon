#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, string> M;

	int n,m;
	cin >> n >> m;	

	string input1, input2;
	for (int i = 0; i < n; i++)
	{
		cin >> input1 >> input2;
		M[input1] = input2;
	}

	string website;
	for (int i = 0; i < m; i++)
	{
		cin >> website;
		cout << M[website] << "\n";
	}
}
