#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

struct document
{
	int number;
	int priority;
};

int main()
{
	int t;
	cin >> t;

	vector<document>::iterator it;
	while (t--)
	{
		deque<document> deque;
		vector<document> vector;
		
		int n, m;
		cin >> n >> m;

		document* doc = new document[n]; //n개의 문서 생성
		for (int i = 0; i < n; i++) //덱 안에 n개의 문서 저장
		{
			int input;
			cin >> input;
			doc[i].number = i;
			doc[i].priority = input;
			deque.push_back(doc[i]);
		}

		while (deque.size() > 1)
		{
			bool popFlag = true; //덱의 front문서가 가장 큰 우선순위면 true
			for (int i = 1; i < deque.size(); i++)
			{
				if (deque.front().priority < deque[i].priority)
				{
					popFlag = false;
				}
			}
			if (popFlag)
			{
				vector.push_back(deque.front());
				deque.pop_front();
			}
			else
			{
				deque.push_back(deque.front());
				deque.pop_front();
			}
		}
		vector.push_back(deque.front());

		for (int i = 0; i < n; i++)
		{
			if (vector[i].number == m)
			{
				cout << i+1 << endl;
				break;
			}
		}
	}
}