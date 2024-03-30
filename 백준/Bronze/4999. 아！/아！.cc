#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


int main()
{
	ios::sync_with_stdio();
	cin.tie();

	string str1, str2;

	cin >> str1;
	cin >> str2;

	if(str1.length() >= str2.length())
		cout << "go";
	else
		cout << "no";
}
