#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int LIS[201];
int arr[201];
int N;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	//base case
	fill(LIS, LIS + 201, 1);

	for (int i = 1; i < N; i++)
	{
		int prevMax = 0;
		for (int j = 0; j < i; j++)
		{
			if(arr[j] < arr[i])
				prevMax = max(prevMax, LIS[j]);
		}
		LIS[i] = prevMax + 1;
	}

	//cout << endl;
	//for (int i = 0; i < N; i++)
	//{
	//	cout << LIS[i] << " ";
	//}
	//cout << endl;

	cout << N - *max_element(LIS, LIS + 201);
}