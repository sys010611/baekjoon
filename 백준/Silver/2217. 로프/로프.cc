#include <iostream>
#include <algorithm>
using namespace std;

int rope[100000];
int weight[100000];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> rope[i];
	}

	sort(rope, rope+n);

	for (int i = 0; i < n; i++)
	{
		weight[i] = rope[i]*(n-i);
	}

	cout << *max_element(weight, weight+n);
}