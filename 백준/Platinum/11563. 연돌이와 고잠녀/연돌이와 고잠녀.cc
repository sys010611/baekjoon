#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

static double INF = 100000000;

struct P
{
	double x, y;

	P(){};
	P(double x, double y)
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
	double x, y;

	Vec(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	Vec(P p1, P p2)
	{
		this->x = p2.x-p1.x;
		this->y = p2.y-p1.y;
	}
};

int cross(double x1, double y1, double x2, double y2)
{
	long long result = (long long)x1 * y2 - (long long)y1 * x2;

	if (result == 0)
		return 0;
	else if (result > 0)
		return 1;
	else
		return -1;
}
double cross(Vec vecA, Vec vecB)
{
	double x1 = vecA.x;
	double y1 = vecA.y;
	double x2 = vecB.x;
	double y2 = vecB.y;

	double result = x1 * y2 - y1 * x2;

	return result;
}

int dot(Vec vecA, Vec vecB)
{
	double x1 = vecA.x;
	double y1 = vecA.y;
	double x2 = vecB.x;
	double y2 = vecB.y;

	long long result = x1*x2 + y1*y2;

	if (result == 0)
		return 0;
	else if (result > 0)
		return 1;
	else
		return -1;
}

double calcDist(P p1, P p2)
{
	return sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
}

double calcDist(line lineA, line lineB)
{
	P p1, p2, p3, p4;

	p1.x = lineA.pS.x;	p1.y = lineA.pS.y;
	p2.x = lineA.pE.x;	p2.y = lineA.pE.y;
	p3.x = lineB.pS.x;	p3.y = lineB.pS.y;
	p4.x = lineB.pE.x;	p4.y = lineB.pE.y;

	// 점들 계산하기 편하게 정렬
	if(p2 < p1)
		swap(p1, p2);
	if(p4 < p3)
		swap(p3, p4);
	if (p3 < p1)
	{
		swap(p1, p3);
		swap(p2, p4);
	}

	double result = INF;

	// 점들 간에 2중 for문 돌려보면서 거리 구해보기
	result = min(result, calcDist(p1, p3));
	result = min(result, calcDist(p1, p4));
	result = min(result, calcDist(p2, p3));
	result = min(result, calcDist(p2, p4));
	result = min(result, calcDist(p3, p1));
	result = min(result, calcDist(p3, p2));
	result = min(result, calcDist(p4, p1));
	result = min(result, calcDist(p4, p2));

	//cout << "점들 간 거리 최솟값: " << result << endl;

	// 한 점에서 다른 선분으로 수선의 발 내리면서 거리 구해보기
	// 그을 수 있는 기준 : AC * AB >= 0, BC * BA >= 0

	P mid;

	mid = P((p3.x + p4.x)/2, (p3.y + p4.y)/2);

	Vec v1_2(p2, p1);
	Vec v1_3(p3, p1);
	Vec v1_4(p4, p1);

	Vec v2_1(p1, p2);
	Vec v2_3(p3, p2);
	Vec v2_4(p4, p2);

	Vec v3_1(p1, p3);
	Vec v3_2(p2, p3);
	Vec v3_4(p4, p3);

	Vec v4_1(p1, p4);
	Vec v4_2(p2, p4);
	Vec v4_3(p3, p4);

	// p1, p2 에서 line 34로	
	if (dot(v3_1, v3_4) >= 0 && dot(v4_3, v4_1) >= 0)
	{
		// 수선의 길이 : 외적의 절댓값 / 선분의 길이
		double length = abs(cross(v1_3, v3_4)) / calcDist(p3, p4);
		//cout << "p1에서 line34로 내린 수선의 길이: " << length << endl;
		result = min(result, length);
	}
	if (dot(v3_2, v3_4) >= 0 && dot(v4_3, v4_2) >= 0)
	{
		// 수선의 길이 : 외적의 절댓값 / 선분의 길이
		double length = abs(cross(v2_3, v3_4)) / calcDist(p3, p4);
		//cout << "p2에서 line34로 내린 수선의 길이: " << length << endl;
		result = min(result, length);
	}
	

	// p3, p4 에서 line 12로	
	if (dot(v1_2, v1_3) >= 0 && dot(v2_1, v2_3) >= 0)
	{
		// 수선의 길이 : 외적의 절댓값 / 선분의 길이
		double length = abs(cross(v3_1, v1_2)) / calcDist(p1, p2);
		//cout << "p3에서 line12로 내린 수선의 길이: " << length << endl;
		result = min(result, length);
	}
	if (dot(v1_2, v1_4) >= 0 && dot(v2_1, v2_4) >= 0)
	{
		// 수선의 길이 : 외적의 절댓값 / 선분의 길이
		double length = abs(cross(v4_1, v1_2)) / calcDist(p1, p2);
		//cout << "p4에서 line12로 내린 수선의 길이: " << length << endl;
		result = min(result, length);
	}

	//cout << "수선의 길이까지 고려한 최솟값 : " <<result << endl;

	return result;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<line> linesA;
	vector<line> linesB;

	int n,m;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		P pS, pE;
		cin >> pS.x >> pS.y >> pE.x >> pE.y;

		linesA.push_back(line(pS, pE));
	}

	for (int i = 0; i < m; i++)
	{
		P pS, pE;
		cin >> pS.x >> pS.y >> pE.x >> pE.y;

		linesB.push_back(line(pS, pE));
	}

	//for (auto l : linesA)
	//{
	//	cout << l.pS.x << " " << l.pS.y << " " << l.pE.x << " " << l.pE.y << endl;
	//}
	//cout << endl;
	//for (auto l : linesB)
	//{
	//	cout << l.pS.x << " " << l.pS.y << " " << l.pE.x << " " << l.pE.y << endl;
	//}

	double result = INF;

	// 2중 for문으로 신촌 도로, 안암 도로 하나씩 선택, 도로 간 거리 구하기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//cout << i << " " << j << endl;
			line lineA = linesA[i];
			line lineB = linesB[j];

			result = min(result, calcDist(lineA, lineB));
		}
	}

	cout << fixed;
	cout.precision(16);
	cout << result;
}
