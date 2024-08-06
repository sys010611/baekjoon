#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define int long long
#define NINF -10000000000

int N;
string expr;

int Calc(int currResult, int currIdx)
{
	//cout << "currResult: " << currResult << endl;

	if(currIdx >= expr.length())
		return currResult;

	// 괄호를 안 넣고 진행
	int newResult = currResult;
	char op = expr[currIdx];
	int num = expr[currIdx+1] - '0';
	switch (op)
	{
		case '+':
			newResult += num;
			break;
		case '-':
			newResult -= num;
			break;
		case '*':
			newResult *= num;
			break;
	}
	int result1 = Calc(newResult, currIdx + 2);



	int result2 = NINF;
	// 괄호를 넣고 진행
	newResult = currResult;
	int smallResult;
	if (currIdx + 3 >= expr.length())
		return result1;
	else
	{
		op = expr[currIdx + 2];
		int num1 = expr[currIdx + 1] - '0';
		int num2 = expr[currIdx + 3] - '0';
		switch (op)
		{
		case '+':
			smallResult = num1 + num2;
			break;
		case '-':
			smallResult = num1 - num2;
			break;
		case '*':
			smallResult = num1 * num2;
			break;


		}
		op = expr[currIdx];
		switch (op)
		{
		case '+':
			newResult += smallResult;
			break;
		case '-':
			newResult -= smallResult;
			break;
		case '*':
			newResult *= smallResult;
			break;
		}
		result2 = Calc(newResult, currIdx + 4);

		return max(result1, result2);
	}	
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	cin >> expr;

	cout << Calc(expr[0] - '0', 1);
}