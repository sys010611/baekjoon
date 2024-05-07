#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N;
int arr[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	// N이 1인 경우 예외처리
	if (N == 1)
	{
		if (arr[0] == 1)
		{
			cout << arr[0]+1;
			return 0;
		}
		else
		{
			cout << 1;
			return 0;
		}
	}

	sort(arr, arr+N);

	if (arr[0] > 1) // 가장 가벼운 추의 무게가 2 이상일 경우, 무게 1은 잴 수 없음
	{
		cout << arr[0] - 1;
		return 0;
	}

	//for(int i=0;i<N;i++) cout << arr[i] << " ";
	//cout << endl;

	//front부터 back까지의 연속된 숫자들은 모두 만들 수 있는 것
	int front = arr[0];
	int back = arr[0];

	for (int i = 1;i < N; i++)
	{
		//cout << "curr : " << arr[i] << endl;
		

		if (front + arr[i] <= back + 1) // 숫자가 이어짐
		{
			back = back + arr[i]; //이어지는 범위 갱신
		}
		else
		{
			if (arr[i] == back + 1 && front + arr[i] <= arr[i] + 1) // 이어지지 않아도, arr[i]가 징검다리가 되는 경우
			{
				back = back + arr[i];
			}
			else
			{
				cout << back + 1;
				return 0;
			}
		}

		//cout << "front : " << front << endl;
		//cout << "back : " << back << endl;
	}

	//아직 안 끝났다면, back 바로 다음의 숫자를 출력
	cout << back+1;
}