#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	stack<int> s;
	int lastTop = 0; //스택에 들어갔던 수의 최댓값
	int n;
	cin >> n;

	vector<int> arr;
	vector<char> result;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}

	for (int i = 0; i < n; i++)
	{
		int curr = arr[i];
		for (int j = lastTop + 1; j <= curr; j++)
		{
			s.push(j);
			result.push_back('+');
		}

		if(s.top() > lastTop)
			lastTop = s.top();

		if (s.top() != curr) //오름차순 삽입 스택으로 표현이 불가능한 경우
		{
			cout << "NO"; return 0;
		}
		s.pop();
		result.push_back('-');
	}

	for (vector<char>::iterator it = result.begin(); it != result.end(); it++)
	{
		cout << *it << "\n";
	}
}