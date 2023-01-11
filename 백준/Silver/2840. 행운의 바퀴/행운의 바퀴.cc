#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	int n=0, k=0; //n: 칸의 수 k: 돌린 횟수
	cin >> n >> k;

	list<char> li(n-1, '?');
	list<char>::iterator it;
	list<char>::iterator it2;

	//첫 입력
	int num;
	char ch;
	cin >> num >> ch;

	li.push_front(ch);

	for (int i = 0; i < k - 1; i++)
	{
		/*cout << "현재 리스트: ";
		for (it = li.begin(); it != li.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;*/

		cin >> num >> ch;
		for (int i = 0; i < num; i++) //글자가 바뀐 수만큼 요소들을 오른쪽으로 이동
		{
			li.push_front(li.back());
			li.pop_back();
		}
		if (li.front() != '?' && li.front() != ch) //빈 자리가 아닐 경우
		{
			cout << "!";
			return 0;
		}
		else
		{
			li.pop_front();
			li.push_front(ch);
		}
	}

	//같은 문자가 두번 나올경우
	for (it = li.begin(); it != li.end(); it++)
	{
		if (*it == '?')
		{
			continue;
		}
		else
		{
			int count = std::count(std::begin(li), std::end(li), *it);
			if (count > 1)
			{
				cout << "!";
				return 0;
			}
		}
	}
	
	while (li.front() != ch)
	{
		//요소들을 왼쪽으로 이동
		li.push_back(li.front());
		li.pop_front();
	}
	//cout << "현재 리스트: ";
	for (it = li.begin(); it != li.end(); it++)
	{
		cout << *it;
	}
}