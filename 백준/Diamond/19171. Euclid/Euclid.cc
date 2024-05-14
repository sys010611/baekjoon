#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

double p_x[3];
double p_y[3];
double p_z[3];

double dx = 0.001;
double dy = 0.001;
double dz = 0.001;

double f(double x, double y, double z)
{
	double result = 0;

	for (int i = 0; i < 3; i++)
	{
		result += sqrt(pow(x - p_x[i], 2) + pow(y - p_y[i], 2) + pow(z - p_z[i], 2));
	}

	return result;
}

double pDerX(double x, double y, double z)
{
	return	(f(x + dx, y, z) - f(x, y, z)) / dx;
}
double pDerY(double x, double y, double z)
{
	return	(f(x, y + dy, z) - f(x, y, z)) / dy;
}
double pDerZ(double x, double y, double z)
{
	return	(f(x, y, z + dz) - f(x, y, z)) / dz;
}

double getDist(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 3; i++)
	{
		cin >> p_x[i] >> p_y[i] >> p_z[i];
	}

	// 초기값 : 모든 source 위치의 평균
	double x = 0, y = 0, z=0;
	for (int i = 0; i < 3; i++)
	{
		x += p_x[i];
		y += p_y[i];
		z += p_z[i];
	}
	x /= 3;
	y /= 3;
	z /= 3;

	//cout << "초기값 : " << endl;
	//cout << "x : " << x << endl;
	//cout << "y : " << y << endl;
	//cout << "z : " << z << endl;

	double longestDist = 0; // 초기값에서 가장 멀리 떨어진 점 찾기. 그걸 토대로 LR을 결정
	for (int i = 0; i < 3; i++)
	{
		longestDist = max(longestDist, getDist(x,y,z, p_x[i], p_y[i], p_z[i]));
	}
	//cout << longestDist << endl;

	double lr = longestDist * 100;

	for (int i = 0; i < 50000; i++)
	{
		if (i % 500 == 0)
		{
			//cout << "epoch  " << i;
			//cout << " / x : " << x;
			//cout << ", y : " << y;
			//cout << ", z : " << z << endl;
		}

		double _x = x - lr * pDerX(x, y, z);
		double _y = y - lr * pDerY(x, y, z);
		double _z = z - lr * pDerZ(x, y, z);

		x = _x;
		y = _y;
		z = _z;

		lr = lr * 0.999;
	}

	cout << fixed;
	cout.precision(15);

	cout << f(x,y,z);

}