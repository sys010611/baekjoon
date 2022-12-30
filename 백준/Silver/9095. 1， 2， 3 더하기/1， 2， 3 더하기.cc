#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	
	while (T--)
	{
		int n;
		cin >> n;

		int arr[11];

		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 4;

		for (int i = 3; i < 11; i++)
		{
			arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
		}

		cout << arr[n-1] << endl;
	}
}