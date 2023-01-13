#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	
	while (T--)
	{
		int flag = 0;
		string str;
		cin >> str;

		stack<char> s;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(') //여는 괄호는 스택에 담기
			{
				s.push('(');
			}
			else if (str[i] == ')') // 닫는 괄호를 만날 시 스택 안의 여는 괄호 pop
			{
				if (s.empty()) //스택이 비어있을 경우
				{
					cout << "NO" << "\n";
					flag = 1;
					break;
				}
				else if (s.top() != '(') //스택안에 여는 괄호가 없을 경우
				{
					cout << "NO" << "\n";
					flag = 1;
					break;
				}
				else
				{
					s.pop();
				}
			}
		}
		if (flag == 1)
			continue;

		//마지막에 스택이 비어있지 않은 경우
		if (!s.empty())
		{
			cout << "NO" << "\n";
		}
		else
		{
			cout << "YES" << "\n";
		}
	}
}