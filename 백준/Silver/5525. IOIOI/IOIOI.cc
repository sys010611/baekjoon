#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count = 0;

	int n, m;
	cin >> n >> m;

	string str;
	cin >> str;

	stack<char> s;

	for (int i = 0; i < m; i++)
	{
		if (s.empty())
		{
			if(str[i] == 'I')
				s.push(str[i]);
			else
				continue;
		}
		else
		{
			if (s.top() != str[i])
			{
				s.push(str[i]);
				if (s.size() == 2 * n + 1)
				{
					s.pop(); s.pop(); //I, O 하나씩 pop
					count++;
				}
			}
			else
			{
				if (s.top() == 'O')
				{
					s = stack<char>(); 
				}
				else
				{
					s = stack<char>();
					s.push('I');
				}
			}
		}
	}
	cout << count;
}
