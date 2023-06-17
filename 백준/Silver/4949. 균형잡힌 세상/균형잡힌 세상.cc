#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (true)
	{
		stack<char> s;
		string str;
		getline(cin, str);

		if(str == ".") break;

		int N = str.length();

		bool notBalanced = false;
		for (int i = 0; i < N; i++)
		{
			switch (str[i])
			{
				case '(':
				case '[':
					s.push(str[i]);
					break;
				case ')':
					if (s.empty() || s.top() != '(')
						notBalanced = true;
					else
						s.pop();
					break;
				case ']':
					if (s.empty() || s.top() != '[')
						notBalanced = true;
					else
						s.pop();
					break;					
			}
			if (notBalanced)
			{
				std::cout << "no" << endl; break;
			}
		}
		if (notBalanced)
			continue;

		if(s.empty())
			std::cout << "yes" << endl;
		else
			std::cout << "no" << endl; 
	}
}