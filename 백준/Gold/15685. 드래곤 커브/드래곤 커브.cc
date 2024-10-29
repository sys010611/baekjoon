#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

typedef pair<int,int> P;

bool map[101][101];
int n;

void DrawCurve(int x, int y, int d, int g)
{
	vector<P> points;

	points.push_back(P(x,y));
	switch (d)
	{
		case 0:
			points.push_back(P(x+1, y));
			break;
		case 1:
			points.push_back(P(x, y-1));
			break;
		case 2:
			points.push_back(P(x-1, y));
			break;
		case 3:
			points.push_back(P(x, y+1));
			break;
	}

	P currRotPoint = points[1];
	P nextRotPoint; // 다음 세대 계산에 쓸 점

	for (int i = 0; i < g; i++)
	{	
		//cout << i <<"세대에서 계산: " << endl;		
		int pSize = points.size();
		for (int j=0;j< pSize;j++)
		{
			P point = points[j];
			if(point == currRotPoint)
				continue;

			P dxdy = P(point.first - currRotPoint.first, point.second - currRotPoint.second);
			P newDxdy;

			if (dxdy.first >= 0 && dxdy.second >= 0)
			{
				newDxdy = P(-abs(dxdy.second), abs(dxdy.first));
			}
			else if (dxdy.first >= 0 && dxdy.second <= 0)
			{
				newDxdy = P(abs(dxdy.second), abs(dxdy.first));
			}
			else if (dxdy.first <= 0 && dxdy.second >= 0)
			{
				newDxdy = P(-abs(dxdy.second), -abs(dxdy.first));
			}
			else if (dxdy.first <= 0 && dxdy.second <= 0)
			{
				newDxdy = P(abs(dxdy.second), -abs(dxdy.first));
			}
			P newPoint = P(currRotPoint.first + newDxdy.first, currRotPoint.second + newDxdy.second);
			points.push_back(newPoint);

			if (j == 0)
			{
				nextRotPoint = newPoint;
			}

			//cout << "point : " << point.first << " " << point.second << endl;
			//cout << "rotPoint: " << currRotPoint.first << " " << currRotPoint.second << endl;
			//cout << "dxdy: " << dxdy.first << " " << dxdy.second << endl;
			//cout << "newDxdy: " << newDxdy.first << " " << newDxdy.second << endl;
			//cout << "newpoint : " << newPoint.first << " " << newPoint.second << endl;
		}
		currRotPoint = nextRotPoint;
	}

	for (auto point : points)
	{
		int row = point.second;
		int col = point.first;

		map[row][col] = true;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(map, 0, sizeof(map));

	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int x,y,d,g;
		cin>>x>>y>>d>>g;

		DrawCurve(x,y,d,g);
	}



	int ret = 0;
	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1])
				ret++;
		}
	}

	cout << ret;

	/*cout<<endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/
}
