#include <iostream> 
#include <string>
#include <vector>
#include <stack>
using namespace std;

int prec(char symbol)
{
	switch (symbol)
	{
	case '(': case ')':
		return 0;
	case '+': case '-':
		return 1;
	}
}

vector<string> infixToPostfix(vector<char>& infix)
{
	stack<char> s;
	vector<string> result;

	char c, t; 
	string num = "";
	for (int i = 0; i < infix.size(); i++)
	{
		c = infix[i];

		if (c >= '0' && c <= '9') //읽어들인 문자가 숫자일 경우
		{
			num += c;
			continue;
		}

		else //읽어들인 문자가 연산자일 경우
		{
			if (num != "") //숫자가 있었다면 result에 push
			{
				result.push_back(num);
				//result.push_back(" ");
				num = "";
			}

			switch (c)
			{
			case '+': case '-':
				while (!s.empty() && prec(s.top()) >= prec(c)) //스택안의 연산자의 우선순위가 c의 우선순위보다 높거나같다면 result에 push
				{
					string oper{s.top()};
					s.pop();
					result.push_back(oper);
					//result.push_back(" ");
				}
				s.push(c); //c는 스택에 push
				break;

			case '(':
				s.push(c);
				break;

			case ')':
				t = s.top(); s.pop();
				while (t != '(')
				{
					string oper({t});
					result.push_back(oper);
					//result.push_back(" ");
					t = s.top(); s.pop();
				}
			}
		}
	}
	if (num != "") //num에 숫자가 들어있을 경우
	{
		result.push_back(num);
		//result.push_back(" ");
		num = "";
	}

	while (!s.empty()) //스택안에 연산자가 남아있을 경우
	{
		t = s.top(); s.pop();
		string oper({ t });
		result.push_back(oper);
		//result.push_back(" ");
	}
	
	return result;
}

int postfixEvaluate(vector<string>& postfix)
{
	stack<int> s;
	string str;

	for (int i = 0; i < postfix.size(); i++)
	{
		str = postfix[i];
		int op1, op2;

		if (str == "+") //연산자가 나올시 계산후 다시 스택에 집어넣기
		{
			op2 = s.top(); s.pop();
			op1 = s.top(); s.pop();
			s.push(op1 + op2);
		}
		else if (str == "-")
		{
			op2 = s.top(); s.pop();
			op1 = s.top(); s.pop();
			s.push(op1 - op2);
		}
		else //숫자가 나올 시 스택에 집어넣기
		{
			s.push(stoi(str));
		}
	}
	return s.top();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string expression;
	cin >> expression;

	vector<char> newExp;
	vector<char>::iterator it;
	vector<string>::iterator it2;

	int len = expression.length();

	char c; bool paranthesesOpened = false;//괄호의 열림 여부
	for (int i = 0; i < len; i++)
	{
		c = expression[i];

		if (c == '-')
		{
			if (!paranthesesOpened) //여는 괄호가 없었을 경우에는 -뒤에 괄호 삽입
			{
				newExp.push_back(c);
				newExp.push_back('(');
				paranthesesOpened = true;
			}
			else
			{
				newExp.push_back(')'); //여는 괄호가 있었을 경우에는 -앞에 괄호 삽입
				newExp.push_back(c);
				newExp.push_back('(');
				paranthesesOpened = true;
			}
		}
		else
		{
			newExp.push_back(c);
		}
	}
	if(paranthesesOpened)
		newExp.push_back(')');

	/*for (it = newExp.begin(); it != newExp.end(); it++)
	{
		cout << *it;
	}
	cout << endl;*/

	vector<string> postfix = infixToPostfix(newExp);

	/*for (it2 = postfix.begin(); it2 != postfix.end(); it2++)
	{
		cout << *it2;
	}
	cout << endl;*/

	cout << postfixEvaluate(postfix);
}