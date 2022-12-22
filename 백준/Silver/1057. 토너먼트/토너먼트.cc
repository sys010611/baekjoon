#include <iostream>
#include <cmath>
using namespace std;

int Calculate(int N, int a, int b)
{
	for (int i = 1; i < 50001; i++) //i = 현재 라운드
	{
		if (a % 2 == 0) //짝수인 경우
			a /= 2;
		else            //홀수인 경우
			a = (a + 1)/2;

		if (b % 2 == 0)
			b /= 2;
		else
			b = (b + 1) / 2;

		if (a == b)
		{
			return i;
		}
	}
}

int main()
{
	int N, a, b;
	cin >> N >> a >> b; //참가자수, 김지민의 번호, 임한수의 번호
	
	cout << Calculate(N, a, b);
}