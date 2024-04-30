#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

struct P
{
	long long x, y;

	P(){};
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
		return *this<ref || *this==ref;
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
		this->x = p2.x-p1.x;
		this->y = p2.y-p1.y;
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
	long long x1,x2,y1,y2;
	x1 = l1.x;
	y1 = l1.y;
	x2 = l2.x;
	y2 = l2.y;

	long long result = (long long)x1 * y2 - (long long)y1 * x2;

	if (result == 0)
		return 0;
	else if (result > 0)
		return 1;
	else
		return -1;
}
int dot(Vec vecA, Vec vecB)
{
	long long x1 = vecA.x;
	long long y1 = vecA.y;
	long long x2 = vecB.x;
	long long y2 = vecB.y;

	long long result = x1*x2 + y1*y2;

	if (result == 0)
		return 0;
	else if (result > 0)
		return 1;
	else
		return -1;
}

/// <summary>
/// 교차점의 개수를 리턴하되, 무수히 많으면 -1 리턴. 교차점을 알고 있을 때에는 교차점도 리턴
/// </summary>
int CheckCrossing(line lineA, line lineB)
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

	//printf("line 1 : (%d, %d) -> (%d,%d) (p1 -> p2)\n", p1.x, p1.y, p2.x, p2.y);
	//printf("line 2 : (%d, %d) -> (%d,%d) (p3 -> p4)\n", p3.x, p3.y, p4.x, p4.y);

	Vec vec1_2(p1, p2);
	Vec vec1_3(p1, p3);
	Vec vec1_4(p1, p4);

	Vec vec2_1(p2, p1);
	Vec vec2_3(p2, p3);
	Vec vec2_4(p2, p4);

	Vec vec3_1(p3,p1);
	Vec vec3_2(p3, p2);
	Vec vec3_4(p3, p4);

	Vec vec4_1(p4,p1);
	Vec vec4_2(p4, p2);
	Vec vec4_3(p4, p3);

	//vec1_2에서 vec1_3, vec1_4로의 방향이 반대여야 함
	int cross1 = cross(vec1_2, vec1_3); 
	int cross2 = cross(vec1_2, vec1_4);

	// 네 점이 모두 한 직선 상에 있는 경우
	if (cross1 == 0 && cross2 == 0)
	{
		//cout << "네 점이 한 직선 상에 있음" << endl;
		if (p2 == p3)
		{
			return 1;
		}
		else if(p3 < p2)
			return -1;
		else
			return 0;
	}
	else
	{
		if (cross1 == 0) // 점 1, 2, 3이 한 직선 상에 있는 경우
		{
			//cout << "1, 2, 3이 한 직선 상" << endl;
			if(p2 < p3)
				return 0;
			else
			{
				return 1;
			}
		}
		else if (cross2 == 0) // 점 1, 2, 4가 한 직선 상에 있는 경우
		{
			//cout << "1, 2, 4이 한 직선 상" << endl;
			if(p2 < p4)
				return 0;
			else
			{
				return 1;
			}
		}
		else
		{
			if(cross1 * cross2 > 0) // 두 방향이 같다면 교차하지 않는 것
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

int N;
bool visited[10]; // 대피소를 사용중인지 여부

int shelterUsage[10];

bool resultFound = false;

vector<P> robots;
vector<P> shelters;

void Backtrack(int currIdx)
{
	//cout << "currIdx : " << currIdx << endl;
	if (currIdx == N) // 끝까지 들어감
	{
		bool success = true;
		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				line l1(robots[i], shelters[shelterUsage[i]]);
				line l2(robots[j], shelters[shelterUsage[j]]);

				if (CheckCrossing(l1, l2) != 0)
				{
					success = false;
				}
			}
		}

		if (success)
		{
			//cout << "모두 겹치지 않는 경우 발견 성공" << endl;
			resultFound = true;
			for (int i = 0; i < N; i++)
			{
				cout << shelterUsage[i]+1 << endl;
			}
		}

		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			shelterUsage[currIdx] = i;
			visited[i] = true;

			Backtrack(currIdx + 1);

			shelterUsage[currIdx] = -1;
			visited[i] = false;

			if(resultFound) 
				return;
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	memset(shelterUsage, -1, sizeof(shelterUsage));
	memset(visited, 0, sizeof(visited));

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		robots.push_back(P(x, y));
	}
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		shelters.push_back(P(x, y));
	}

	Backtrack(0);
}
