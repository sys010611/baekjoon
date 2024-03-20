#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int> P;

const int INF = 10000000;

int n,s;
int arr[100000];
int minLength = INF;

int main()
{
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int left = 0; int right = 0;
	int currNum = arr[0];
	while (true)
	{
		if (currNum >= s)
		{
			int currLength = right-left + 1;
			if (currLength < minLength)
			{
				minLength = currLength;
			}
		}

		if (currNum < s)
		{
			right++;

			if(right >= n) // 끝까지 가서 숫자를 더 늘릴 수 없음.
				break;

			currNum += arr[right];
		}
		else if (currNum >= s)
		{
			currNum -= arr[left];
			left++;

			if(left >= n) // 끝까지 가서 숫자를 더 줄일 수 없음.
				break;
		}
	}

	if(minLength == INF)
		cout << 0;
	else
		cout << minLength;
}