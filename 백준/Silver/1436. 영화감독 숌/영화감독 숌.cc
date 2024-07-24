#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> numbers;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int num = 666; ; num++)
	{
		string str = to_string(num) ;
		int count = 0;
		int maxCount = 0;

		for (int i = 0; i < str.length(); i++)
		{
			if(str[i] == '6')
				count++;
			else
				count = 0;

			maxCount = max(maxCount, count);
		}

		if(maxCount >= 3)
			numbers.push_back(num);

		if(numbers.size() >= 10000)
			break;
	}

	cout << numbers[n-1];
}