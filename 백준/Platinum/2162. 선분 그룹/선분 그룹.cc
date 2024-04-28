#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct P
{
	int x, y;

	bool operator<(const P& ref)
	{
		if (this->x != ref.x)
			return this->x < ref.x;
		else
			return this->y < ref.y;
	}
};
struct Vec
{
	int x, y;

	Vec(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

int cross(int x1, int y1, int x2, int y2)
{
	long long result = (long long)x1 * y2 - (long long)y1 * x2;

	if (result == 0)
		return 0;
	else if (result > 0)
		return 1;
	else
		return -1;
}

bool checkCrossing(P p1, P p2, P p3, P p4)
{
	bool result = true;

	// p1 p2, p3 p4가 x축 값 기준 정렬되도록
	if (p2 < p1)
		swap(p1, p2);
	if (p4 < p3)
		swap(p3, p4);
	if (p3 < p1)
	{
		swap(p1, p3);
		swap(p2, p4);
	}

	Vec v1_2(p2.x - p1.x, p2.y - p1.y);
	Vec v1_3(p3.x - p1.x, p3.y - p1.y);
	Vec v1_4(p4.x - p1.x, p4.y - p1.y);

	Vec v3_4(p4.x - p3.x, p4.y - p3.y);
	Vec v3_1(p1.x - p3.x, p1.y - p3.y);
	Vec v3_2(p2.x - p3.x, p2.y - p3.y);

	// v1_2에서 v1_3으로의 방향, v1_4로의 방향이 반대여야 함
	int dir1 = cross(v1_2.x, v1_2.y, v1_3.x, v1_3.y);
	int dir2 = cross(v1_2.x, v1_2.y, v1_4.x, v1_4.y);

	if (dir1 * dir2 > 0) // 같은 방향이라면, 교차하지 않는 것
	{
		result = false;
	}
	if (dir1 == 0 && dir2 == 0) // 네 점이 모두 일직선 상에 있는 경우
	{
		//cout << "네 점이 일직선상 " << endl;
		if (p2 < p3) // p3이 p2 바깥에 있는 경우
		{
			result = false;
			//cout << "1" << endl;
		}
		else
		{
			result = true;
			return result;
		}
	}
	else
	{
		if (dir1 == 0) // 점 1, 2, 3이 일직선 상에 있는 경우
		{
			//P3이 P1과 P2 사이에 있지 않으면, 교차 실패
			if (p2 < p3)
			{
				result = false;
				//cout << "2" << endl;
			}
			else
			{
				result = true;
				return result;
			}
		}
		if (dir2 == 0) // 점 1, 2, 4가 일직선 상에 있는 경우
		{
			if (p2 < p4)
			{
				result = false;
				//cout << "3" << endl;
			}
			else
			{
				result = true;
				return result;
			}
		}
	}

	// v3_4에서 v3_1로의 방향, v3_2로의 방향이 반대여야 함
	dir1 = cross(v3_4.x, v3_4.y, v3_1.x, v3_1.y);
	dir2 = cross(v3_4.x, v3_4.y, v3_2.x, v3_2.y);

	if (dir1 * dir2 > 0) // 같은 방향이라면, 교차하지 않는 것
	{
		result = false;
	}

	//네 점이 일직선인 경우는 위에서 했으므로, 굳이 다시 하지 않음

	// 점 3, 4, 1이 일직선 상에 있는 경우는 검사할 필요 없음

	if (dir2 == 0) // 점 3, 4, 2가 일직선 상에 있는 경우
	{
		if (p2 < p3 || p4 < p2)
		{
			result = false;
			//cout << "5" << endl;
		}
		else
		{
			result = true;
			return true;
		}
	}
	return result;
}

int p[3000];

/// <summary>
/// 루트를 반환
/// </summary>
int Find(int n)
{
	while (p[n] >= 0)
	{
		n = p[n];
	}

	return n;
}

/// <summary>
/// b를 a의 자식으로 붙인다.
/// </summary>
void Merge(int a, int b)
{
	int rootA = Find(a);
	int rootB = Find(b);

	p[rootA] += p[rootB]; // 집합의 크기 합해서 저장

	p[rootB] = rootA; // B를 A에 붙이기
}

pair<P,P> lineList[3000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(p, -1, sizeof(p));

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		P p1,p2;
		cin >> p1.x >> p1.y >> p2.x >> p2.y;

		lineList[i] = pair<P,P>(p1,p2);
	}

	// 2중 for문 돌리면서 선분마다 교차 여부 판별, 교차하는 것 있으면 그 선분의 그룹에 들어가기
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			//cout << i << "와 " << j << "번 선분 교차 판별 " << endl;

			bool result = checkCrossing(lineList[i].first, lineList[i].second, lineList[j].first, lineList[j].second);
			//cout << "교차 판별 결과 : " << result << endl;
			if (result == true) // 선분이 교차할 시, Merge (i 를 j의 자식으로)
			{
				if (Find(i) != Find(j))
				{
					Merge(i,j);
					//cout << "merge 완료  " << endl;
				}
			}
		}
	}

	//cout << "그룹의 수, 가장 큰 그룹의 크기 구하기" << endl;
	int groupCount = 0;
	int maxGroupSize = 1;

	for (int i = 0; i < N; i++)
	{
		if (p[i] < 0) // 그룹의 개수 = 루트의 개수
		{
			groupCount++;

			// 루트일 경우, 해당 그룹의 크기도 확인
			maxGroupSize = max(maxGroupSize, abs(p[i]));
		}
	}

	cout << groupCount << endl << maxGroupSize;
}
