#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
using namespace std;

map<string, int> trees;

int main()
{
	cout<<fixed;
	cout.precision(4);

	int totalCount = 0;
	string s;
	while (true)
	{
		getline(cin, s);
		if(cin.eof()) break;

		if (s == "테스트")
			break;

		totalCount++;
		if (trees.find(s) == trees.end())
		{
			trees[s] = 1;
		}
		else
		{
			trees[s]++;
		}
	}

	for (pair<const string, int>& item : trees)
	{
		double portion = (double)item.second / totalCount * 100;

		portion = round(portion*10000)/10000;

		cout << item.first << " " << portion << endl;
	}
}