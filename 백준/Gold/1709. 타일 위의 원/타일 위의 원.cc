#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define int long long

double getDist_squared(int x, int y)
{
	return x*x + y*y;
}

signed main()
{
	int n;
	cin >> n;

	n/=2; // 한 사분면에서만 계산할 거니까 절반으로 줄이기
	
	int x = 0;
	int y = n-1;

	int count = 0;

	while (y >= 0)
	{	
		count ++;

		//cout << "x, y : ";
		//cout << x << " " << y << endl;

		int nextDist_squared = getDist_squared(x+1,y);

		if (nextDist_squared < n*n) // 오른쪽으로 한칸 가도 된다면 가기
		{
			x++;
		}
		else if (nextDist_squared > n*n) // 오른쪽으로 한칸 갔을 때 원을 벗어난다면 아래로 가기
		{
			y--;
		}
		else if (nextDist_squared == n*n) // 오른쪽으로 한칸 갔을 때 원에 걸친다면, 대각선 아래로 가기
		{
			x++;
			y--;
		}
	}

	cout << count*4;
}