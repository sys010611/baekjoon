#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N;

vector<long long> arr;

const long long INF = 30000000000;

long long currResult = INF;

long long a, b, c;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());

	//2개는 2중 for문으로 선택하고, 나머지 하나를 이분 탐색으로 찾기
	for (int i = 0; i <= arr.size() - 3; i++)
	{
		for (int j = i + 1; j <= arr.size() - 2; j++)
		{
			long long currSum = arr[i] + arr[j]; // 두 용액을 섞은 값

			auto otherIt = lower_bound(arr.begin() + j+1, arr.end(), -currSum); // 0으로 중화시키는 것에 최대한 가까운 수 찾기

			if (otherIt != arr.end() && abs(currSum + *otherIt) < currResult)
			{
				currResult = abs(currSum + *otherIt);
				a = arr[i];
				b = arr[j];
				c = *otherIt;
			}

			if (otherIt > arr.begin() + j + 1 && abs(currSum + *(otherIt - 1)) < currResult)
			{
				currResult = abs(currSum + *(otherIt - 1));
				a = arr[i];
				b = arr[j];
				c = *(otherIt-1);
			}
		}
	}

	cout << a << " " << b << " " << c;
}