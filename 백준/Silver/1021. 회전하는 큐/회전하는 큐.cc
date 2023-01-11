#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	int N=0, M=0;
	cin >> N >> M; // N: 큐의 크기 M: 뽑을 숫자의 개수

	int result = 0; //오른쪽, 왼쪽 이동 횟수

	list<int> queue;
	list<int> poppingNumber;
	list<int>::iterator it;

	for (int i = 0; i < N; i++)
		queue.push_back(i+1);

	for (int i = 0; i < M; i++) //뽑아야 할 숫자
	{
		int input;
		cin >> input;
		poppingNumber.push_back(input);
	}

	while (!poppingNumber.empty())
	{
		/* //큐 확인
		cout << "현재 큐: ";
		for (it = queue.begin(); it != queue.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;*/

		//뽑을 숫자의 큐에서의 위치
		int location = -1;
		for (it = queue.begin(); it != queue.end(); it++)
		{
			if (*it == poppingNumber.front())
			{
				location = distance(queue.begin(), it) + 1;
			}
		}

		//cout << "뽑을 숫자의 위치: " << location << endl;

		//cout << "2, 3번 계산 수: " << result << endl << endl;

		if (poppingNumber.front() == queue.front()) //바로 뽑으면 되는 경우
		{
			queue.pop_front();
			poppingNumber.pop_front();
			continue;
		}
		else if (location > (queue.size() / 2) + 1) //뽑고자 하는 숫자가 큐의 오른쪽에 가까울 경우
		{
			queue.push_front(queue.back());
			queue.pop_back();
			result++;
		}
		else if (location <= (queue.size() / 2) + 1) //뽑고자 하는 숫자가 큐의 정중앙이거나 왼쪽에 가까울 경우
		{
			queue.push_back(queue.front());
			queue.pop_front();
			result++;
		}
	}

	cout << result;
}