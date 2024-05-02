#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

struct P
{
	long long x, y;

	P() {};
	P(long long x, long long y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator<(const P& ref)
	{
		if (this->x != ref.x)
			return this->x < ref.x;
		else
			return this->y < ref.y;
	}

	bool operator==(const P& ref)
	{
		return (this->x == ref.x && this->y == ref.y);
	}

	bool operator<=(const P& ref)
	{
		return *this < ref || *this == ref;
	}
};
struct line
{
	P pS, pE;

	line(P pS, P pE)
	{
		this->pS = pS;
		this->pE = pE;
	}
};
struct Vec
{
	long long x, y;

	Vec(long long x, long long y)
	{
		this->x = x;
		this->y = y;
	}
	Vec(P p1, P p2)
	{
		this->x = p2.x - p1.x;
		this->y = p2.y - p1.y;
	}
};

int cross(long long x1, long long y1, long long x2, long long y2)
{
	long long result = (long long)x1 * y2 - (long long)y1 * x2;

	if (result == 0)
		return 0;
	else if (result > 0)
		return 1;
	else
		return -1;
}
int cross(Vec l1, Vec l2)
{
	long long x1, x2, y1, y2;
	x1 = l1.x;
	y1 = l1.y;
	x2 = l2.x;
	y2 = l2.y;

	return cross(x1, y1, x2, y2);
}

int dot(Vec vecA, Vec vecB)
{
	long long x1 = vecA.x;
	long long y1 = vecA.y;
	long long x2 = vecB.x;
	long long y2 = vecB.y;

	long long result = x1 * x2 + y1 * y2;

	if (result == 0)
		return 0;
	else if (result > 0)
		return 1;
	else
		return -1;
}

/// <summary>
/// 교차 유무 리턴
/// </summary>
bool CheckCrossing(line lineA, line lineB)
{
	P p1, p2, p3, p4;

	p1.x = lineA.pS.x;	p1.y = lineA.pS.y;
	p2.x = lineA.pE.x;	p2.y = lineA.pE.y;
	p3.x = lineB.pS.x;	p3.y = lineB.pS.y;
	p4.x = lineB.pE.x;	p4.y = lineB.pE.y;

	// 점들 계산하기 편하게 정렬
	if (p2 < p1)
		swap(p1, p2);
	if (p4 < p3)
		swap(p3, p4);
	if (p3 < p1)
	{
		swap(p1, p3);
		swap(p2, p4);
	}

	//printf("line 1 : (%d, %d) -> (%d,%d) (p1 -> p2)\n", p1.x, p1.y, p2.x, p2.y);
	//printf("line 2 : (%d, %d) -> (%d,%d) (p3 -> p4)\n", p3.x, p3.y, p4.x, p4.y);

	Vec vec1_2(p1, p2);
	Vec vec1_3(p1, p3);
	Vec vec1_4(p1, p4);

	Vec vec2_1(p2, p1);
	Vec vec2_3(p2, p3);
	Vec vec2_4(p2, p4);

	Vec vec3_1(p3, p1);
	Vec vec3_2(p3, p2);
	Vec vec3_4(p3, p4);

	Vec vec4_1(p4, p1);
	Vec vec4_2(p4, p2);
	Vec vec4_3(p4, p3);

	//vec1_2에서 vec1_3, vec1_4로의 방향이 반대여야 함
	int cross1 = cross(vec1_2, vec1_3);
	int cross2 = cross(vec1_2, vec1_4);

	// 네 점이 모두 한 직선 상에 있는 경우
	if (cross1 == 0 && cross2 == 0)
	{
		//cout << "네 점이 한 직선 상에 있음" << endl;
		if(p2<p3)
			return 0;
		else
			return 1;
	}
	else
	{
		if (cross1 == 0) // 점 1, 2, 3이 한 직선 상에 있는 경우
		{
			//cout << "1, 2, 3이 한 직선 상" << endl;
			if (p2 < p3)
				return 0;
			else
			{
				return 1;
			}
		}
		else if (cross2 == 0) // 점 1, 2, 4가 한 직선 상에 있는 경우
		{
			//cout << "1, 2, 4이 한 직선 상" << endl;
			if (p2 < p4)
				return 0;
			else
			{
				return 1;
			}
		}
		else
		{
			if (cross1 * cross2 > 0) // 두 방향이 같다면 교차하지 않는 것
				return 0;
		}
	}

	//vec3_4에서 vec3_1, vec3_2로의 방향이 반대여야 함
	cross1 = cross(vec3_4, vec3_1);
	cross2 = cross(vec3_4, vec3_2);

	if (cross1 == 0) // 점 3, 4, 1이 한 직선 상에 있는 경우
	{
		//cout << "3, 4, 1이 한 직선 상" << endl;
		if (p1 == p3)
		{
			return 1;
		}
		else
			return 0;
	}
	else if (cross2 == 0) // 점 3, 4, 2가 한 직선 상에 있는 경우
	{
		//cout << "3, 4, 2이 한 직선 상" << endl;
		if (p4 < p2 || p2 < p3)
			return 0;
		else
		{
			return 1;
		}
	}
	else
	{
		if (cross1 * cross2 > 0) // 두 방향이 같다면 교차하지 않는 것
			return 0;
	}

	// 여기까지 왔으면 교차하는 것
	return 1;
}

Vec LineToVec(line l)
{
	return Vec(l.pE.x - l.pS.x, l.pE.y - l.pS.y);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2; // 선분 입력
		line newLine(P(x1, y1), P(x2, y2));


		int xmin, ymin, xmax, ymax;
		cin >> xmin >> ymin >> xmax >> ymax; //직사각형 입력

		if (xmax < xmin) swap(xmax, xmin);
		if (ymax < ymin) swap(ymax, ymin);

		//직사각형의 네 변 뽑아내기
		line l1(P(xmin, ymin), P(xmax, ymin));
		line l2(P(xmax, ymin), P(xmax, ymax));
		line l3(P(xmax, ymax), P(xmin, ymax));
		line l4(P(xmin, ymax), P(xmin, ymin));

		line lines[4] = { l1,l2,l3,l4 };



		// 4개의 변에 대해 각각 새로운 선분과의 교차 여부를 검사
		bool found = false;
		for (int i = 0; i < 4; i++)
		{
			bool checkResult;
			checkResult = CheckCrossing(lines[i], newLine);   

			if (checkResult == true)
			{
				found = true;
				break;
			}
		}

		bool including  = true;

		int sideToLineDir = cross(LineToVec(lines[0]), Vec(lines[0].pS, newLine.pS));

		// 선분이 사각형 안에 쏙 들어간 경우: 각 변마다 선분의 두 점으로의 두 방향이 일치해야 함
		for (int i = 0; i < 4; i++)
		{
			Vec sideVec = LineToVec(lines[i]);
			Vec vec1(lines[i].pS, newLine.pS);
			Vec vec2(lines[i].pS, newLine.pE);

			if(cross(sideVec, vec1) != sideToLineDir)
				including = false;
			if (cross(sideVec, vec2) != sideToLineDir)
				including = false;
		}

		if (found || including)
			cout << 'T' << endl;
		else
			cout << 'F' << endl;
	}
}
