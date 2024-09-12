#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> fruits;
int fruitCount[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(fruitCount, fruitCount + 10, 0);

	cin >> N;

	if (N <= 2)
	{
		cout << N;
		return 0;
	}

	fruits.resize(N);
	for(int i=0;i<N;i++)
		cin >> fruits[i];

	// 투포인터
	int result = 0; // S와 E의 최대 거리를 저장
	int S = 0, E = 1;
	fruitCount[fruits[S]]++;
	fruitCount[fruits[E]]++;
	while (true)
	{
		int currCount = 0;
		for (int i = 1; i < 10; i++)
		{
			if (fruitCount[i] > 0)
			{
				currCount++;
			}
		}

		if (currCount <= 2)
		{
			result = max(result, E-S+1); // 갱신
			
			// E 늘려보기
			E++;
			if(E >= N)
				break;
			fruitCount[fruits[E]]++;
		}
		else
		{
			// S 당겨오기 (S가 E를 역전할 일은 없다고 가정 가능)
			fruitCount[fruits[S]]--;
			S++;
		}
	}

	cout << result;
}