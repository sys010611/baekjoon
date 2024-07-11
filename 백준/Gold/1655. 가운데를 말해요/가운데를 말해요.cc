#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void swap()
{
	// 양쪽의 top을 서로 바꾼다.
	int temp = minHeap.top();

	minHeap.pop();
	minHeap.push(maxHeap.top());

	maxHeap.pop();
	maxHeap.push(temp);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		// max, min, max, min 번갈아 넣기
		if (i % 2 == 0) 
		{
			maxHeap.push(num);
		}
		else
		{
			minHeap.push(num);
		}

		if (!maxHeap.empty() && !minHeap.empty())
		{
			// 최대 힙의 top이 최소 힙의 top보다는 항상 작거나 같아야 함
			while (maxHeap.top() > minHeap.top())
			{
				swap();
			}
		}

		cout << maxHeap.top() << '\n';
	}
}