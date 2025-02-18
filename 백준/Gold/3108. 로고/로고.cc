#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define MAX 1001

struct Rect
{
	Rect(int a, int b, int c, int d)
	{
		xMin = a;
		yMin = b;
		xMax = c;
		yMax = d;
	}
	int xMin, xMax, yMin, yMax;
};

vector<Rect> rectangles;
int p[MAX];

bool IsIntersecting(Rect A, Rect B)
{
	//printf("A : %d, %d / %d, %d\n", A.xMin, A.yMin, A.xMax, A.yMax);
	//printf("B : %d, %d / %d, %d\n", B.xMin, B.yMin, B.xMax, B.yMax);

	// x축 비교
	if (A.xMin > B.xMin)
		swap(A, B);
	if (A.xMax < B.xMin)
		return false;

	// y축 비교
	if (A.yMin > B.yMin)
		swap(A, B);
	if (A.yMax < B.yMin)
		return false;

	// 포함관계 체크
	if (A.xMin < B.xMin &&
		A.xMax > B.xMax &&
		A.yMin < B.yMin &&
		A.yMax > B.yMax)
	{
		return false;
	}


	return true;
}

int Find(int n)
{
	if (p[n] == -1)
		return n;
	else
		return p[n] = Find(p[n]);
}

void Merge(int rootA, int rootB)
{
	// B를 A에 병합
	p[rootB] = rootA;
	return;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(p, p + MAX, -1);

	int N;
	cin >> N;

	rectangles.push_back(Rect(0, 0, 0, 0));
	for (int i = 0; i < N; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);

		rectangles.push_back(Rect(x1, y1, x2, y2));
	}

	for (int i = 0; i < rectangles.size(); i++)
	{
		for (int j = i + 1; j < rectangles.size(); j++)
		{
			//printf("%d, %d 검사\n", i, j);
			if (IsIntersecting(rectangles[i], rectangles[j]))
			{
				//cout << "겹침 판정" << endl;
				int rootA = Find(i);
				int rootB = Find(j);
				if(rootA != rootB)
					Merge(rootA, rootB);
				//cout << "병합" << endl;
			}
		}
	}

	int unionCount = 0;
	for (int i = 0; i < rectangles.size(); i++)
	{
		if (p[i] == -1)
			unionCount++;
		//cout << p[i] << endl;
	}
	cout << unionCount - 1;
}
