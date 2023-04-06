#include <iostream> 
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char> s;

	string input;
	cin >> input;

	int result = 0;
	int openingParNum = 0; // 여는 괄호가 시작된 횟수

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
		{
			if (input[i + 1] == ')') //레이저인 경우
			{
				result += s.size();
				//cout << result << endl;
				i++; //다음 ')'는 건너뛰기

				//cout << "openingparnum: " << openingParNum << endl;
				for (; openingParNum != 0; openingParNum--)
				{
					s.pop(); //한번 자른 쇠막대기는 이후에 자를때 개수가 각각 1개씩만 증가함
				}
			}
			else //쇠막대기인 경우
			{
				s.push('('); //처음에 2개씩 집어넣기
				s.push('(');
				openingParNum++;
			}
		}
		else if (input[i] == ')') //쇠막대기 1개가 끝나는 경우
		{
			s.pop();
		}
	}

	cout << result;

	return 0;
}

