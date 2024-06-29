#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

stack<pair<char, int>> S;

int main()
{
	while (true)
	{
		string name;
		int age;
		int weight;
		cin>>name>>age>>weight;

		if(name == "#" && age == 0 && weight == 0) return 0;

		if (age > 17 || weight >= 80)
		{
			cout << name << " Senior" << endl;
		}
		else
		{
			cout << name << " Junior" << endl;
		}
	}
}