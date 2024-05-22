#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

#define int long long

struct Point
{
	int x, y, p, q, origIdx;

	Point() : Point(0, 0, 1, 0, -1) {}
	Point(int x, int y, int origIdx) : Point(x, y, 1, 0, origIdx) {}
	Point(int x, int y, int p, int q, int origIdx)
	{
		this->x = x;
		this->y = y;
		this->p = p;
		this->q = q;
		this->origIdx = origIdx;
	}

	bool operator<(const Point& ref)
	{
		if (y != ref.y)
		{
			return y < ref.y;
		}
		return x < ref.x;
	}
};

vector<Point> points;
vector<int> used;

double GetDist(Point& A, Point& B)
{
	return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}
double GetDist(Point& p)
{
	return sqrt(pow(p.x, 2) + pow(p.y, 2));
}
double GetDist(int pointIdxA, int pointIdxB)
{
	return GetDist(points[pointIdxA], points[pointIdxB]);
}

bool CCWsort(Point& a, Point& b)
{
	if (a.q * b.p != a.p * b.q)
	{
		return a.q * b.p < a.p * b.q;
	}
	
	// CCW의 값이 0인 경우
	return GetDist(a, points[0]) < GetDist(b, points[0]);
}

struct Vec
{
	int x, y;
	Vec(Point p1, Point p2)
	{
		x = p2.x - p1.x;
		y = p2.y - p1.y;
	}
};



void PrintPoints()
{
	cout << "--------------------------------" << endl;
	for (auto point : points)
	{
		cout << point.x << " " << point.y << endl;
	}
	cout << "--------------------------------" << endl;
}

int CCW(Point& A, Point& B, Point& C)
{
	Vec vec_ab = Vec(A, B);
	Vec vec_ac = Vec(A, C);

	int a = vec_ab.x;
	int b = vec_ab.y;
	int c = vec_ac.x;
	int d = vec_ac.y;
	return a * d - b * c;
}



signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; 
	cin >> n;

	int availablePointCount = n;
	int currFloor = 1;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		points.push_back(Point(x, y, i));
	}
	used.resize(n);
	fill(used.begin(), used.end(), 0);


	//PrintPoints();

	while (availablePointCount > 2)
	{
		sort(points.begin(), points.end()); // 0번 점 : 최하단 좌측 점

		for (int i = 1; i < points.size(); i++)
		{
			points[i].p = points[i].x - points[0].x;
			points[i].q = points[i].y - points[0].y;
		}

		sort(points.begin() + 1, points.end(), CCWsort); // 1~n 번 점들을 반시계방향 정렬

		//cout << currFloor << "층 제작, 현재 남은 점 : " << availablePointCount << endl;
		stack<int> S;

		S.push(0);
		S.push(1);

		int next = 2;
		while (next < points.size())
		{
			while (S.size() >= 2)
			{
				int first = S.top();
				S.pop();
				int second = S.top();

				if (CCW(points[second], points[first], points[next]) > 0)
				{
					S.push(first);
					break;
				}
				else
				{
					continue;
				}
			}
			S.push(next);
			next++;
		}

		//cout << currFloor << "층 완성" << endl;
		if (S.size() < 3)
		{
			//cout << "볼록 껍질 만들 수 없었음" << endl;
			break;
		}

		availablePointCount -= S.size();
		while (!S.empty())
		{
			int currPoint = S.top();
			S.pop();

			//cout << currFloor << "층에 " << points[currPoint].x << ", " << points[currPoint].y << " 점 사용" << endl;

			// currPoint 사용했다고 기록
			used[points[currPoint].origIdx] = currFloor;

			points.erase(points.begin()+currPoint);

		}
		currFloor++;
	}

	for (int i = 0; i < n; i++)
	{
		cout << used[i] << " ";
	}
}


