#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int k;
	cin >> k;

	stack<int> s;

	for (int i = 0; i < k; i++)
	{
		int input;
		cin >> input;

		if (input != 0)
			s.push(input);
		else
			s.pop();
	}

	int result = 0;
	while (!s.empty())
	{
		result += s.top();
		s.pop();
	}
	cout << result;
}