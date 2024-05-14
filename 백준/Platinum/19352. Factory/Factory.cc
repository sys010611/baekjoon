#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

double p_x[1000];
double p_y[1000];

double dx = 0.001;
double dy = 0.001;

int N;

double f(double x, double y)
{
	double result = 0;

	for (int i = 0; i < N; i++)
	{
		result += sqrt(pow(x - p_x[i], 2) + pow(y - p_y[i], 2));
	}

	return result;
}

double pDerX(double x, double y)
{
	return	(f(x + dx, y) - f(x, y)) / dx;
}
double pDerY(double x, double y)
{
	return	(f(x, y + dy) - f(x, y)) / dy;
}

double getDist(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int z;
	cin >> z;
	while (z--)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> p_x[i] >> p_y[i];
		}

		// 초기값 : 모든 store 위치의 평균
		double x=0, y=0;
		for (int i = 0; i < N; i++)
		{
			x += p_x[i];
			y += p_y[i];
		}
		x /= N;
		y /= N;

		dx = 0.001;
		dy = 0.001;
		double lr = 1000000;

		for (int i = 0; i < 50000; i++)
		{
			//if (i % 500 == 0)
			//{
			//	cout << "epoch  " << i;
			//	cout << " / x : " << x;
			//	cout << ", y : " << y << endl;
			//}

			double _x = x - lr * pDerX(x, y);
			double _y = y - lr * pDerY(x, y);

			x = _x;
			y = _y;

			lr = lr * 0.999;
		}

		cout << fixed;
		cout.precision(15);

		cout << x << " " << y << endl;
	}
}