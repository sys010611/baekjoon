#include <iostream>
#include <cmath>
using namespace std;

void Calculate(int x1, int y1, int x2, int y2, int& count)
{
	int cX, cY, r; //각 행성계의 중점, 반지름
	cin >> cX >> cY >> r;

	bool containsA, containsB; // 행성계가 출발점, 도착점을 포함하는지

	double distA, distB ;
	distA = sqrt(pow(x1 - cX, 2) + pow(y1 - cY, 2)); //출발점과 행성 중심의 거리
	distB = sqrt(pow(x2 - cX, 2) + pow(y2 - cY, 2)); //도착점과 행성 중심의 거리

	containsA = (distA < r) ? true : false;
	containsB = (distB < r) ? true : false;

	if (containsA && !containsB)
		count++;

	else if (!containsA && containsB)
		count++;

	return;
}

int main()
{
	int T;
	cin >> T;
	
	while (T--) // 각 테스트 케이스
	{
		int x1, y1, x2, y2; //출발점, 도착점
		int planetNum; // 행성계의 개수
		int count = 0; // 진입, 이탈 횟수

		cin >> x1 >> y1 >> x2 >> y2;
		cin >> planetNum;
		
		while (planetNum--) //각 행성계
		{
			Calculate(x1, y1, x2, y2, count);
		}
		
		cout << count << "\n";
		count = 0;
	}
}