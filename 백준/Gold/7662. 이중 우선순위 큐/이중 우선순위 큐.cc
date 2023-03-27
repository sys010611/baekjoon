#include <iostream> 
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

bool valid[1000000];

void syncMinHeap(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& minHeap)
{
	while (!minHeap.empty() && !valid[minHeap.top().second])
	{
		minHeap.pop();
	}
}

void syncMaxHeap(priority_queue<pair<int, int>>& maxHeap)
{
	while (!maxHeap.empty() && !valid[maxHeap.top().second])
	{
		maxHeap.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		priority_queue<pair<int, int>> maxHeap;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

		for (int i = 0; i < 1000000; i++)
			valid[i] = false;

		int k;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			char command;
			int num;
			cin >> command >> num;

			switch (command)
			{
			case 'I':
				maxHeap.push({ num,i });
				minHeap.push({ num,i });
				valid[i] = true;
				//cout << "valid" << i << "is true" << endl;
				break;
			case 'D':
				if (num == -1)
				{
					syncMinHeap(minHeap);
					if (!minHeap.empty())
					{
						valid[minHeap.top().second] = false;
						//cout << "valid" << minHeap.top().second << "is false" << endl;
						minHeap.pop();
					}
				}
				else if (num == 1)
				{
					syncMaxHeap(maxHeap);
					if (!maxHeap.empty())
					{
						valid[maxHeap.top().second] = false;
						//cout << "valid" << maxHeap.top().second << "is false" << endl;
						maxHeap.pop();
					}
				}
				break;
			}
		}
		syncMaxHeap(maxHeap);
		syncMinHeap(minHeap);
		if (maxHeap.empty())
			cout << "EMPTY" << endl;
		else
			cout << maxHeap.top().first << " " << minHeap.top().first << endl;
	}
}