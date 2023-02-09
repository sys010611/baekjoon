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

	priority_queue<int, vector<int>, greater<int>> pq;

	int n,a,b,sum,input, result=0;
	cin >> n;
	while (n--)
	{
		input;
		cin >> input;
		pq.push(input);
	}

	while (pq.size() >= 2)
	{
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		sum = a+b;
		result += sum;
		pq.push(sum);
	}

	cout << result;
}