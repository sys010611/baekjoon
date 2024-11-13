#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;

int p[3001];

struct point
{
	int x,y,R;
};

bool isReachable(point a, point b)
{
	float dist = sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2));

	if ((float)a.R + b.R >= dist)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void merge(int rootA, int rootB)
{
	p[rootB] = rootA;
}

int find(int n)
{
	if(p[n] == -1)
	{
		return n;
	}
	else
	{
		return p[n] = find(p[n]);
	}
}

int main()
{
	int t;cin>>t;
	while (t--)
	{
		int N; cin >> N;
		vector<point> vec(N);
		for (int i = 0; i < N; i++)
		{
			cin >> vec[i].x >> vec[i].y >> vec[i].R;
		}

		memset(p, -1, sizeof(p));

		for (int i = 0; i < N-1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (isReachable(vec[i], vec[j]))
				{
					int rootA = find(i);
					int rootB = find(j);

					if(rootA != rootB)
						merge(rootA, rootB);
				}
			}
		}

		int count = 0;
		for (int i = 0; i < N; i++)
		{
			if (p[i] == -1)
			{
				count ++;
			}
		}
		cout << count << endl;
	}
}
