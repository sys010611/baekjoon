#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	int N=0, K=0;
	cin >> N >> K;

	list<int> li;
	list<int> newLi;
	list<int>::iterator it;

	for (int i = 1; i < N+1; i++)
	{
		li.push_back(i);
	}

	while (!li.empty())
	{
		for (int i = 0; i < K-1; i++)
		{
			li.push_back(li.front());
			li.pop_front();
		}
		newLi.push_back(li.front());
		li.pop_front();
	}

	cout << "<";
	for (it = newLi.begin(); *it != newLi.back(); it++)
	{
		cout << *it << ", ";
	}
	cout << newLi.back();
	cout << ">";
}