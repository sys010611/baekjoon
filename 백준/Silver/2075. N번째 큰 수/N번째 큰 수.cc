#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	int input;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		pq.push(input);
	}

	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			pq.push(input);
		}
		for (int k = 0; k < n; k++)
			pq.pop();
	}

	cout << pq.top();
}