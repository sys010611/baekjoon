#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

#define int long long

struct Point
{
	int x, y, p, q;

	Point() : Point(0,0,1,0){}
	Point(int x, int y): Point(x,y,1,0){}
	Point(int x, int y, int p, int q)
	{
		this->x = x;
		this->y = y;
		this->p = p;
		this->q = q;
	}

	bool operator<(const Point& ref)
	{
		if (q * ref.p != p * ref.q)
		{
			return q*ref.p < p*ref.q;
		}
		if (y != ref.y)
		{
			return y < ref.y;
		}
		return x < ref.x;
	}
};
struct Vec
{
	int x, y;
	Vec(Point p1, Point p2)
	{
		x = p2.x-p1.x;
		y = p2.y-p1.y;
	}
};

vector<Point> points;

void PrintPoints()
{
	for (auto point : points)
	{
		cout << point.x << " " << point.y << endl;
	}
}

int CCW(Point& A, Point& B, Point& C)
{
	Vec vec_ab = Vec(A, B);
	Vec vec_ac = Vec(A, C);

	int a = vec_ab.x;
	int b = vec_ab.y;
	int c = vec_ac.x;
	int d = vec_ac.y;
	return a*d - b*c;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x,y;
		cin >> x >> y;
		points.push_back(Point(x,y));
	}

	sort(points.begin(), points.end());

	for (int i = 1; i < points.size(); i++)
	{
		points[i].p = points[i].x - points[0].x;
		points[i].q = points[i].y - points[0].y;
	}

	sort(points.begin()+1, points.end());

	// PrintPoints();

	stack<int> S;
	S.push(0);
	S.push(1);

	int next = 2;
	while (next < n)
	{
		while (S.size() >= 2)
		{
			int first = S.top(); 
			S.pop();
			int second = S.top();

			if(CCW(points[second], points[first], points[next]) > 0)
			{
				S.push(first);
				break;
			}
			else
			{
				// cout << points[first].x << ", " << points[first].y << "제외" << endl;
				continue;
			}
		}
		S.push(next);
		next++;
	}

	cout << S.size();
}


