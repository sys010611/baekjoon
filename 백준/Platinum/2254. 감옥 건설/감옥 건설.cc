#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
#include <stack>
using namespace std;

#define int long long

struct Point
{
	int x, y, p, q;

	Point() : Point(0, 0, 1, 0) {}
	Point(int x, int y) : Point(x, y, 1, 0) {}
	Point(int x, int y, int p, int q)
	{
		this->x = x;
		this->y = y;
		this->p = p;
		this->q = q;
	}

	bool operator<(const Point& ref)
	{
		if ((long long)q * ref.p != (long long)p * ref.q)
		{
			return (long long)q * ref.p < (long long)p * ref.q;
		}
		if (y != ref.y)
		{
			return y < ref.y;
		}
		return x < ref.x;
	}

	bool operator==(const Point& ref)
	{
		return x == ref.x && y == ref.y;
	}
};
struct Vec
{
	long long x, y;
	Vec(Point p1, Point p2)
	{
		x = p2.x - p1.x;
		y = p2.y - p1.y;
	}
};

int CCW(Point& A, Point& B, Point& C)
{
	Vec vec_ab = Vec(A, B);
	Vec vec_ac = Vec(A, C);

	int a = vec_ab.x;
	int b = vec_ab.y;
	int c = vec_ac.x;
	int d = vec_ac.y;
	long long result = (long long)a * d - (long long)b * c;

	if (result > 0) return 1;
	else if (result < 0) return -1;
	else return 0;
}

deque<Point> points;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p_x, p_y;
	cin >> n >> p_x >> p_y;

	// 포함해야할 점
	Point P = Point(p_x, p_y);

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		points.push_back(Point(x, y));
	}

	sort(points.begin(), points.end()); // x,y값으로 정렬, 0번 점이 기준점이 됨

	int count = 0;
	while (points.size() > 2) // 담을 만드려면 점이 최소 3개
	{
		for (int i = 1; i < points.size(); i++)
		{
			points[i].p = points[i].x - points[0].x;
			points[i].q = points[i].y - points[0].y;
		}

		sort(points.begin() + 1, points.end()); // 0번점 기준 반시계방향 정렬

		//담 하나 만들기
		stack<Point> S;
		S.push(points[0]);
		S.push(points[1]);

		for (int i = 2; i < points.size(); i++)
		{
			Point next = points[i];
			while (S.size() >= 2)
			{
				Point first = S.top();
				S.pop();
				Point second = S.top();

				if (CCW(second, first, next) > 0)
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
		}

		int columnCount = S.size();

		// 담 생성 완료, 그 담이 P를 포함하는지 검사
		bool including = true;
		Point first = S.top();
		auto it = remove(points.begin(), points.end(), first);
		points.resize(it - points.begin());

		S.pop();
		Point second = S.top();
		int stdDir = CCW(second, first, P);

		while (S.size() >= 2)
		{
			// 점 2개씩 뽑아가면서 계속 P와 CCW 수행, 방향이 계속 일치해야 함
			Point first = S.top(); S.pop();
			auto it = remove(points.begin(), points.end(), first);
			points.resize(it - points.begin());

			Point second = S.top();
			int dir = CCW(second, first, P);

			if (dir != stdDir || dir == 0)
			{
				including = false;
				break;
			}
		}

		it = remove(points.begin(), points.end(), S.top());
		points.resize(it - points.begin());

		if (!including)
			break;
		else
			count++;
	}

	cout << count;
}