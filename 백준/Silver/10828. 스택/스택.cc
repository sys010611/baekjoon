#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	stack<int> s;

	string input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;

		if (input == "push")
		{
			int num;
			cin >> num;
			s.push(num);
		}
		else if (input == "top")
		{
			if(s.empty())
				cout << -1 << endl;
			else
				cout << s.top() << endl;
		}
		else if (input == "size")
		{
			cout << s.size() << endl;
		}
		else if (input == "pop")
		{
			if (s.empty())
				cout << -1 << endl;
			else
			{
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (input == "empty")
		{
			cout << s.empty() << endl;
		}
	}
}