#include <iostream> 
#include <stack>
using namespace std;

int priority(char c)
{
	switch (c)
	{
		case '+': case '-':
			return 1;
		case '*': case '/':
			return 2;
		case '(': case ')':
			return 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char> s;

	string exp;
	cin >> exp;

	for (int i = 0; i < exp.length(); i++)
	{
		//피연산자라면 그대로 출력
		if (exp[i] >= 'A' && exp[i] <= 'Z')
		{
			cout << exp[i];
		}
		//연산자라면 스택에 넣기
		else if(exp[i] == '+' || exp[i] == '*' || exp[i] == '/' || exp[i] == '-')
		{
			if (s.empty())
			{
				s.push(exp[i]);
				continue;
			}
			while (!s.empty() && priority(s.top()) >= priority(exp[i])) // 스택안에서 우선순위가 높거나 같은 연산자들 모두 출력후 pop
			{
				cout << s.top(); 
				s.pop();
			}
			s.push(exp[i]); //그 후 스택에 push
		}
		else if (exp[i] == '(')
		{
			s.push(exp[i]);
		}
		else if (exp[i] == ')') //괄호 사이 연산자들은 한꺼번에 pop
		{
			while (true)
			{
				char t = s.top();
				s.pop();

				if (t == '(')
					break;

				cout << t;
			}
		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	return 0;
}

