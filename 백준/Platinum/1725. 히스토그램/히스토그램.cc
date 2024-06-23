#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define int long long

int N;
int heights[100000];

signed main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> heights[i];
	}

	int result = 0;

	stack<int> S; // 히스토그램의 idx를 저장

	for (int i = 0; i < N; i++)
	{
		//cout << "i : " << i << endl;
		//cout << "STACK SIZE : " << S.size() << endl;

		if (S.empty())
		{
			S.push(i);
			continue;
		}

		int currHeight = heights[i];
		int prevHeight = heights[S.top()];

		if (currHeight > prevHeight) // 나보다 높으면 push
		{
			S.push(i);
		}
		else // 나보다 같거나 작으면 pop, 최대넓이 확인 및 갱신
		{
			while (!S.empty())
			{
				//cout << "STACK TOP : " << S.top() << endl;

				prevHeight = heights[S.top()];
				if (prevHeight >= currHeight)
				{
					if (S.size() == 1) // 스택의 마지막 아이템을 빼는 경우
					{
						S.pop();
						int width = i;
						result = max(result, width * prevHeight);
						//cout << "RESULT: " << result << endl;
					}
					else
					{
						S.pop();

						int currWidth = i-1 - S.top();
						int currArea = currWidth * prevHeight;

						result = max(result, currArea);
						//cout << "RESULT: " << result << endl;
					}
					
				}
				else
				{
					break;
				}
			}
			S.push(i);
		}
	}

	while (!S.empty())
	{
		//cout << "STACK SIZE : " << S.size() << endl;
		if (S.size() == 1)
		{
			//cout << "마지막 기둥 처리" << endl;
			int height = heights[S.top()];
			result = max(result, height * N);
			//cout << "RESULT: " << result << endl;

			break;
		}
		else
		{
			int currHeight = heights[S.top()];
			S.pop();

			int currWidth = N-1 - S.top();
			
			int currArea = currWidth * currHeight;

			result = max(result, currArea);
			//cout << "RESULT: " << result << endl;


			continue;
		}
	}	

	cout << result;
}