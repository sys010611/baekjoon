#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct P
{
	int x, y;
};
struct vec
{
	int x,y;

	vec(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

P p1, p2, p3;

/// <summary>
/// 리턴 값이 양수일 시 반시계방향, 음수일 시 시계방향
/// </summary>
int cross(int x1, int y1, int x2, int y2)
{
	return x1*y2 - y1*x2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cin >> p3.x >> p3.y;

	vec p1p2(p2.x-p1.x, p2.y-p1.y);
	vec p1p3(p3.x - p1.x, p3.y - p1.y);

	int result = cross(p1p2.x, p1p2.y, p1p3.x, p1p3.y);
	if (result == 0)
		cout << 0;
	else if(result > 0)
		cout << 1;
	else
		cout << -1;
}
