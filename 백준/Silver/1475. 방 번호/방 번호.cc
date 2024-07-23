#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numbers[10] = {0,};

int main()
{
	string N; cin >> N;
	for (auto c : N)
	{
		int num = c - '0';

		if (num == 9)
			numbers[6]++;
		else
			numbers[num]++;
	}
	
	if(numbers[6]%2 == 1)
		numbers[6] = numbers[6]/2+1;
	else
		numbers[6] = numbers[6]/2;

	cout << *max_element(numbers, numbers+10);
}