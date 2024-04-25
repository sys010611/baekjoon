#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct P
{
	int x,y;
};
struct Vec
{
	int x,y;

	Vec(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

int cross(int x1, int y1, int x2, int y2)
{
	long long result = (long long)x1*y2 - (long long)y1*x2;

	if(result == 0)
		return 0;
	else if (result > 0)
		return 1;
	else
		return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	P p1,p2,p3,p4;

	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	cin >> p3.x >> p3.y >> p4.x >> p4.y;

	Vec v1_2(p2.x - p1.x, p2.y - p1.y);
	Vec v1_3(p3.x - p1.x, p3.y - p1.y);
	Vec v1_4(p4.x - p1.x, p4.y - p1.y);

	Vec v3_4(p4.x - p3.x, p4.y - p3.y);
	Vec v3_1(p1.x - p3.x, p1.y - p3.y);
	Vec v3_2(p2.x - p3.x, p2.y - p3.y);

	int result = 1;

	// v1_2에서 v1_3으로의 방향, v1_4로의 방향이 반대여야 함
	int dir1 = cross(v1_2.x, v1_2.y, v1_3.x, v1_3.y);
	int dir2 = cross(v1_2.x, v1_2.y, v1_4.x, v1_4.y);

	if (dir1 * dir2 > 0) // 같은 방향이라면, 교차하지 않는 것
	{
		result = 0;
	}

	// v3_4에서 v3_1로의 방향, v3_2로의 방향이 반대여야 함
	dir1 = cross(v3_4.x, v3_4.y, v3_1.x, v3_1.y);
	dir2 = cross(v3_4.x, v3_4.y, v3_2.x, v3_2.y);

	if (dir1 * dir2 > 0) // 같은 방향이라면, 교차하지 않는 것
	{
		result = 0;
	}

	cout << result;
}
