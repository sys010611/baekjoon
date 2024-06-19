#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main()
{
	long long arr[5];
	for(int i=0;i<5;i++) cin >> arr[i];

	long long result=0;

	for (int i = 0; i < 5; i++)
	{
		result += arr[i]*arr[i];
	}
	result %= 10;
	cout << result;
}