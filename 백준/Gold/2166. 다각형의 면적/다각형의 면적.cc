#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;

struct P
{
	int x,y;
};
struct Vec
{
	int x,y;
};

int N;
P points[10000];
double result;

LL cross(LL x1, LL y1, LL x2, LL y2)
{
	return x1*y2 - y1*x2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> points[i].x >> points[i].y;
	}

	for (int i = 0; i < N - 2; i++)
	{
		Vec vec1;
		Vec vec2;

		vec1.x = points[i + 1].x - points[0].x;
		vec1.y = points[i + 1].y - points[0].y;

		vec2.x = points[i + 2].x - points[0].x;
		vec2.y = points[i + 2].y - points[0].y;

		//printf("vec1 : (%d, %d)", vec1.x, vec1.y);
		//printf("vec2 : (%d, %d)", vec2.x, vec2.y);

		double triangle = (double)cross(vec1.x, vec1.y, vec2.x, vec2.y) / 2.0;
		//cout << "삼각형의 면적: " << triangle << endl;

		result += triangle;
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(result);
}
