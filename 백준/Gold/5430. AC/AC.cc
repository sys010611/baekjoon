#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		bool errorFlag = false;
		deque<int> deq;

		string method;
		cin >> method;

		int n;
		cin >> n;

		string list;
		cin >> list;

		//숫자의 개수보다 D가 더 많을 경우 error
		int deleteCount = 0;
		for (int i = 0; i < method.length(); i++)
		{
			if (method[i] == 'D')
			{
				deleteCount++;
			}
		}
		if (deleteCount > n)
		{
			cout << "error" << "\n";
			continue;
		}

		//list에서 숫자만 덱에 push  (1이상 100 이하)
		if (list.length() > 2)
		{
			list.erase(list.begin());
			list.erase(list.end() - 1);
			string separator = ",";
			int cur_position = 0;
			int position;
			while ((position = list.find(separator, cur_position)) != std::string::npos)
			{
				int len = position - cur_position;
				std::string result = list.substr(cur_position, len);
				deq.push_back(stoi(result));
				cur_position = position + 1;
			}
			std::string result = list.substr(cur_position);
			deq.push_back(stoi(result));
		}
		
		char currentDeletePos = 'L';
		for (int i = 0; i < method.length(); i++)
		{
			if (method[i] == 'R')
			{
				if (currentDeletePos == 'L')
				{
					currentDeletePos = 'R';
				}
				else
					currentDeletePos = 'L';
			}
			else if (method[i] == 'D')
			{
				if (currentDeletePos == 'L')
				{
					deq.pop_front();
				}
				else
					deq.pop_back();
			}
		}

		//R이 짝수번 나왔을시 정상 출력, 홀수번일시 역순 출력
		int rotationCount = 0;
		for (int i = 0; i < method.length(); i++)
		{
			if (method[i] == 'R')
			{
				rotationCount++;
			}
		}

		if (!deq.empty())
		{
			if (rotationCount % 2 == 0)
			{
				cout << "[";
				for (int i = 0; i < deq.size() - 1; i++)
				{
					cout << deq[i] << ",";
				}
				cout << deq.back() << "]" << "\n";
			}
			else if (rotationCount % 2 == 1)
			{
				cout << "[";
				for (int i = deq.size()-1; i > 0; i--)
				{
					cout << deq[i] << ",";
				}
				cout << deq.front() << "]" << "\n";
			}
		}
		else
		{
			cout << "[]" << "\n";
		}
	}
}