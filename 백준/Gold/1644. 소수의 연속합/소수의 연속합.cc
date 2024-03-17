#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;
int result = 0;

vector<int> primeList;
bool isPrime[4000001];

void SetPrimeList()
{
	for (int i = 2; i <= N; i++)
	{
		if (isPrime[i])
		{
			primeList.push_back(i);

			for (int j = i + i; j <= N; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	if (N == 1)
	{
		cout << 0;
		return 0;
	}

	memset(isPrime, true, sizeof(isPrime));

	SetPrimeList();

	//for(int i=0;i<primeList.size();i++)
	//	cout << primeList[i] << endl;

	int left = 0; 
	int right = 0;

	int currSum = primeList[0];

	//투포인터
	while ((left <= right)) // 여기에 못들어가는 경우: 값을 계속 줄이려다 더이상 못 줄일 때. 즉 primeList[right]가 이미 N을 넘어선 것.
	{
		
		//cout << "left: " << left << endl;
		//cout << "right : " << right << endl;
		//cout << "currSum : " << currSum << endl;
		if (currSum < N)
		{
			right++;

			if(right < primeList.size()) // 아직 값을 더 키울 수 있다면 그대로, 아니면 break.
				currSum += primeList[right];
			else
				break;
		}
		else if (currSum > N)
		{
			currSum -= primeList[left];
			left++;
		}
		else // currSum == N
		{
			result += 1;
			currSum -= primeList[left];
			left++;
		}
	}

	cout << result;
}