#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	int N; //풍선의 개수
	cin >> N;

	list<int> result;

	list<int> li;// 풍선 list (0, 1, 2, ... , N-1)
	list<int>::iterator it;

	for (int i = 0; i < N; i++)
	{
		li.push_back(i+1);
	}
	
	int* paper = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> paper[i];
	}

	//풍선 터뜨리기
	while (li.size() > 1)
	{
		/*cout << "풍선 현황: ";
		for (it = li.begin(); it != li.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;*/

		int number = paper[li.front()-1];
		result.push_back(li.front());
		li.pop_front();

		if (number < 0) //왼쪽으로 이동
		{
			for (int i = 0; i < abs(number); i++)
			{
				li.push_front(li.back());
				li.pop_back();
			}
		}
		else if (number > 0) //오른쪽으로 이동
		{
			for (int i = 0; i < number-1; i++)
			{
				li.push_back(li.front());
				li.pop_front();
			}
		}
	}
	//list에 남은 마지막 풍선 하나 result로 이동
	result.push_back(li.front());

	for (it = result.begin(); it != result.end(); it++)
	{
		cout << *it << " ";
	}
}