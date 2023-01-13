#include <iostream>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int n; //피연산자의 개수
	cin >> n;
	string problem; //주어진 후위표기식
	cin >> problem;
	stack<double> stack;

	map<char, double> m; //알파벳, 숫자
	for (int i = 0; i < 26; i++) //A~Z 0으로 초기화
	{
		m.insert({'A' + i, 0});
	}
	
	for (int i = 0; i < n; i++) //피연산자에 해당하는 값 입력
	{
		cin >> m['A' + i];
	}
	
	/*for (map<char, double>::iterator itr = m.begin(); itr != m.end(); ++itr) //map 확인
	{
		cout << itr->first << ":" << itr->second << " ";
	}
	cout << endl;*/

	for (int i = 0; i < problem.length(); i++)
	{
		if (problem[i] == '+') // +일 경우
		{
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();
			double result = a+b;
			stack.push(result);
		}
		else if (problem[i] == '*') // *일 경우
		{
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();
			double result = a * b;
			stack.push(result);
		}
		else if (problem[i] == '-') // -일 경우
		{
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();
			double result = b - a;
			stack.push(result);
		}
		else if (problem[i] == '/') // /일 경우
		{
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();
			double result = b / a;
			stack.push(result);
		}
		else //피연산자일 경우 스택에 추가 (숫자로 변환해서)
		{
			stack.push(m[problem[i]]);
		}
	}

	std::cout << fixed;
	std::cout.precision(2);
	std::cout << stack.top();
}