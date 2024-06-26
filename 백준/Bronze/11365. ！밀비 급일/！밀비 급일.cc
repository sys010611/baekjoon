#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;



int main()
{
	while (true)
	{
		string s;
		getline(cin, s);
		if(s == "END") return 0;

		for (int i = s.size() - 1; i > -1; i--)
		{
			cout << s[i];
		}
		cout << endl;
	}
}