#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<string, int> map2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	cin >> n >> m;

	map<int, string> map;

	for (int i = 1; i < n+1; i++)
	{
		string input;
		cin >> input;
		map[i] = input;
		map2[input] = i;
	}

	//cout << "--------------------" << "\n";

	for (int i = 0; i < m; i++)
	{
		string input;
		cin >> input;

		if (isdigit(input[0]) == 0) //숫자가 아닌 경우
		{
			cout << map2[input] << "\n";
		}
		else
		{
			cout << map[stoi(input)] << "\n"; 
		}
	}
}