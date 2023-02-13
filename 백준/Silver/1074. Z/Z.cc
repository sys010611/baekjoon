#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, r, c, n;
	cin >> N >> r >> c;

	int phase = -1;
	int result = 0;

	n = N;

	while (n > 0)
	{
		//cout << "현재 n: " << n << endl;

		//이전 단계에서 목적지가 위치한 영역에 따라 목적지 조정
		if (phase == 2)
		{
			c -= pow(2, n);
			//cout << "r, c: " << r << ", " << c << endl;
		}
		else if (phase == 3)
		{
			r -= pow(2, n);
			//cout << "r, c: " << r << ", " << c << endl;
		}
		else if (phase == 4)
		{
			r -= pow(2, n);
			c -= pow(2, n);
			//cout << "r, c: " << r << ", " << c << endl;
		}

		//문제를 4등분
		if (r >= 0 && r <= pow(2, n - 1) - 1 && c >= 0 && c <= pow(2, n - 1) - 1) //phase 1
		{
			phase = 1;
			//cout << "phase: " << phase << endl;
		}
		else if (r >= 0 && r <= pow(2, n - 1) - 1 && c >= pow(2, n - 1) && c <= pow(2, n) - 1) //phase 2
		{
			phase = 2;
			//cout << "phase: " << phase << endl;
			result += pow(2, n - 1) * pow(2, n - 1) * 1;
		}
		else if (r >= pow(2, n - 1) && r <= pow(2, n) - 1 && c >= 0 && c <= pow(2, n - 1) - 1) //phase 3
		{
			phase = 3;
			//cout << "phase: " << phase << endl;
			result += pow(2, n - 1) * pow(2, n - 1) * 2;
		}
		else if (r >= pow(2, n - 1) && r <= pow(2, n) - 1 && c >= pow(2, n - 1) && c <= pow(2, n) - 1) //phase 4
		{
			phase = 4;
			//cout << "phase: " << phase << endl;
			result += pow(2, n - 1) * pow(2, n - 1) * 3;
		}
		//cout << "현재 result: " << result << endl << endl;

		n--;
	}

	cout << result;
}