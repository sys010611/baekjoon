#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

struct Point
{
	int x,y, p, q;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
		p = -1;
		q = -1;
	}
};

bool cmp1(Point& a, Point& b)
{
	// p,q가 아직 안 정해진 경우
	if (a.y != b.y)
		return a.y < b.y;
	
	return a.x < b.x;
}
bool cmp2(Point& a, Point& b)
{
	//p, q가 정해졌을 경우
	if(a.p * b.q - a.q * b.p != 0)
		return a.p * b.q - a.q * b.p > 0;

	return cmp1(a, b);
}

struct Vector
{
	int x,y;
	Vector(Point& a, Point& b)
	{
		this->x = b.x-a.x;
		this->y = b.y-a.y;
	}
};

double CCW(Vector a, Vector b)
{
	double x1 = a.x;
	double y1 = a.y;
	double x2 = b.x;
	double y2 = b.y;

	return x1*y2 - x2*y1;
}


vector<Point> points;

void PrintPoints()
{
	cout << "point 목록: " << endl;
	for (auto& item : points)
	{
		cout << item.x << ", " << item.y << endl;
	}
	cout << endl;
}

void MakeConvexHull(vector<int>& result)
{
	stack<int> s;

	s.push(0);
	s.push(1);

	for (int next = 2; next < points.size(); next++)
	{
		while (s.size() >= 2)
		{
			int curr = s.top(); s.pop();
			int prev = s.top();

			Vector v1(points[prev], points[curr]);
			Vector v2(points[prev], points[next]);

			int ccw = CCW(v1, v2);

			if (ccw > 0)
			{
				s.push(curr);
				break;
			}
			else
			{
				continue;
			}
		}
		s.push(next);
	}

	while (!s.empty())
	{
		result.push_back(s.top());
		s.pop();
	}
}

double GetArea(vector<int>& resultVec)
{
	double result = 0;

	int pIdxOrig =resultVec[0];
	for (int i = 1; i < resultVec.size()-1; i++)
	{
		int pIdx1 = resultVec[i];
		int pIdx2 = resultVec[i+1];

		Vector v1(points[pIdxOrig], points[pIdx1]);
		Vector v2(points[pIdxOrig], points[pIdx2]);

		result += CCW(v1, v2) / 2;
	}

	return -result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x,y;
		cin >> x >> y;
		points.push_back(Point(x,y));
	}

	if (n <= 2)
	{
		cout << 0;
		return 0;
	}

	//x, y기준 정렬
	sort(points.begin(), points.end(), cmp1);

	points[0].p = 0; points[0].q = 0;
	for (int i = 1; i < points.size(); i++)
	{
		points[i].p = points[i].x - points[0].x;
		points[i].q = points[i].y - points[0].y;
	}

	//PrintPoints();

	//p, q 이용, 반시계방향으로 정렬
	sort(points.begin()+1, points.end(), cmp2);

	//PrintPoints();

	vector<int> result;
	MakeConvexHull(result);

	if (result.size() <= 2)
	{
		cout << 0;
		return 0;
	}
	
	//cout << "만들어진 볼록껍질: " << endl;
	//for (auto item : result)
	//{
	//	cout << item << ", ";
	//	cout << points[item].x << " " << points[item].y << endl;
	//}

	double area = GetArea(result);

	//cout << "면적 : " <<  area << endl;

	cout << (int)(area / 50);
}