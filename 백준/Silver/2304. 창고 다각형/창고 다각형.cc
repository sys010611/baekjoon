#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct cylinder
{
	int position = 0;
	int height = 0;
};

int cmp(cylinder a, cylinder b)
{
	return a.position < b.position;
}

int main()
{
	stack<cylinder> stack1; //왼쪽 -> 오른쪽
	stack<cylinder> stack2; //오른쪽 -> 왼쪽

	int n; //기둥의 개수
	cin >> n;
	int result = 0;

	cylinder* cylinders = new cylinder[n];

	for (int i = 0; i < n; i++)
	{
		cin >> cylinders[i].position >> cylinders[i].height;
	}

	sort(cylinders, cylinders+n, cmp);

	/*for (int i = 0; i < n; i++) //기둥 정렬 확인
	{
		cout << i+1 << "번째 기둥: " << cylinders[i].position << " " << cylinders[i].height << endl;
	}*/

	for (int i = 0; i < n; i++)
	{
		if (stack1.empty() || cylinders[i].height > stack1.top().height) // 새로운 기둥이 높이가 더 높으면 스택에 추가
		{
			stack1.push(cylinders[i]);
		}
		else
			continue;
	}

	for (int i = n - 1; i > -1; i--)
	{
		if (stack2.empty() || cylinders[i].height > stack2.top().height) //역순
		{
			stack2.push(cylinders[i]);
		}
		else
			continue;
	}

	if (stack1.top().position == stack2.top().position) //최고높이 기둥이 하나일 경우
	{
		result += stack1.top().height; //가장 높은 기둥의 넓이
	}
	else
	{
		result += (stack2.top().position+1 - stack1.top().position) * stack1.top().height;
	}

	while (stack1.size() >= 2)
	{
		cylinder a = stack1.top();
		stack1.pop();
		cylinder b = stack1.top();

		result += (a.position - b.position) * b.height;
	}
	while (stack2.size() >= 2)
	{
		cylinder a = stack2.top();
		stack2.pop();
		cylinder b = stack2.top();

		result += (b.position - a.position) * b.height;
	}
	cout << result;
}