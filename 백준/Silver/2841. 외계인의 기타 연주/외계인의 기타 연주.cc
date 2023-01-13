#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	int n; //음의 수
	int p; //프렛의 수
	cin >> n >> p;
	int count = 0;// 손가락의 이동 횟수

	//6개의 스택을 담는 배열
	stack<int>* string = new stack<int>[7];
	
	for (int i = 0; i < n; i++)
	{
		int st,fret;
		cin >> st >> fret;
		if (string[st].empty() || fret > string[st].top()) //더 높은 프렛을 잡아야 할 시 push
		{
			string[st].push(fret);
			count++;
		}
		else //더 낮은 프렛을 잡아야 할 시 pop
		{
			while (fret < string[st].top())
			{
				string[st].pop();
				count++;
				if (string[st].empty())
				{
					string[st].push(fret);
					count++;
				}
			}
			if (fret == string[st].top())
			{
				continue;
			}
			else
			{
				string[st].push(fret);
				count++;
			}
		}
	}
	cout << count;
}