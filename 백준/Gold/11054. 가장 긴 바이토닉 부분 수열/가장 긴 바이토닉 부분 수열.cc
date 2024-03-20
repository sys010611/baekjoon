#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int LIS[1000];
int LDS[1000];
int LBS[1000];
int arr[1000];
int N;


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	//base case;
	fill(LIS, LIS+1000, 1);
	fill(LDS, LDS + 1000, 1);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i]) // 붙일 수 있으면 붙인 것, 지금 것 비교해서 더 긴걸로
			{
				LIS[i] = max(LIS[i], 1 + LIS[j]);
			}
		}
	}

	//for (int i = 0; i < N; i++)
	//{
	//	cout << LIS[i] << " ";
	//}

	for (int i = N-1; i >=0; i--)
	{
		for (int j = N-1; j > i; j--)
		{
			if (arr[i] > arr[j]) // 붙일 수 있으면 붙인 것, 지금 것 비교해서 더 긴걸로
			{
				LDS[i] = max(LDS[i], 1 + LDS[j]);
			}
		}
	}

	//for (int i = 0; i < N; i++)
	//{
	//	cout << LDS[i] << " ";
	//}

	int maxLDSLength = 0;

	for (int i = 0; i < N; i++)
	{
		int LIS_length = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				LIS_length = max(LIS_length, LIS[j]);
			}
		}

		int LDS_length = 0;
		for (int j = N - 1; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				LDS_length = max(LDS_length, LDS[j]);
			}
		}

		maxLDSLength = max(maxLDSLength, LIS_length + 1 + LDS_length);
	}

	cout << maxLDSLength;
}