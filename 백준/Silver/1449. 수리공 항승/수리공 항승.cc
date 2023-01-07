#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int L;
    int tapeCount = 1; //필요한 테이프 개수 (계산에서 누락되는 마지막 부분 1개 추가)
    int startPoint; //기준점

    cin >> N >> L;

    vector<int> points(N); //물이 새는 곳들
    for(int i = 0; i < N; i++)
    {
	    cin >> points[i];
    }

    sort(points.begin(), points.end());
   
    /*std::vector<int>::iterator iter; //벡터 확인
    for (iter = points.begin(); iter != points.end(); iter++)
    {
        std::cout << "Iterator : " << *iter << std::endl;
    }*/

    startPoint = points[0];

    for (int i = 1; i < points.size(); i++)
    {
	    if (points[i] > startPoint + L-1) //테이프로 커버할 범위를 넘을 경우
        {
			tapeCount++;
            startPoint = points[i];

            //cout << "끊긴 부분: " << points[i-1] << ", " << points[i] << endl;
        }
    }
    
    cout << tapeCount;
}