#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

long long N;
long long dice[6];
vector<int> threes;
vector<int> twos;

bool isFacing(int a, int b)
{
	if ((a == 0 && b == 5) || (b == 0 && a == 5))
		return true;
	if ((a == 1 && b == 4) || (b == 1 && a == 4))
		return true;
	if ((a == 2 && b == 3) || (b == 2 && a == 3))
		return true;

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < 6; i++)
	{
		cin >> dice[i];
	}

	if (N == 1)
	{
		sort(dice, dice + 6);
		cout << dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
		return 0;
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 6; k++) // 3개의 면이 서로 마주보면 안됨
			{
				if (i!=j && j != k && k != i && !isFacing(i,j) && !isFacing(j,k) && !isFacing(k,i))
					threes.push_back(dice[i] + dice[j] + dice[k]);
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i!=j && !isFacing(i,j)) // 서로 마주보면 안됨
			{
				twos.push_back(dice[i] + dice[j]);
			}
		}
	}

	sort(threes.begin(), threes.end());
	sort(twos.begin(), twos.end());
	sort(dice, dice + 6);

	long long three = threes[0]; //3면
	long long two = twos[0]; // 2면
	long long one = dice[0]; //1면

	//cout << "3면 최솟값 : " << three << endl;
	//cout << "2면 최솟값 : " << two << endl;
	//cout << "1면 최솟값 : " << one << endl;

	long long result = 0;

	//맨 위층
	//꼭짓점 4개 -> 3면
	result += 4 * three;
	// 꼭짓점 제외 모서리 4(n-2)개
	result += 4 * (N-2) * two;
	// 정수리부분 
	result += (N-2)*(N-2) * one;

	//그 아래층 모두
	long long lowers = 0;
	lowers += (long long)4 * two;
	lowers += (long long)4*(N-2) * one;
	result += lowers * (long long)(N-1);

	cout << result;
}