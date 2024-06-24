#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int N;
int arr[100];

int main()
{
	cin >> N;
	string line;
	cin >> line;
	for (int i = 0; i < N; i++)
	{
		arr[i] = line[i]-'0';
	}

	int result =0;
	for(int i=0;i<N;i++)result+=arr[i];

	cout << result;
}