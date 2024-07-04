#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

#define int long long

int N, C;
vector<int> pos;

bool Check(int minDist)
{
	int deployCount = 0;
	int lastPos = -1000000000;
	for (int i = 0; i < N; i++)
	{
		int currPos = pos[i];
		if (currPos - lastPos >= minDist)
		{
			deployCount++;
			lastPos = currPos;
		}
	}
	
	//cout << "최소 거리: " << minDist << endl;
	//cout << "결과 : " << deployCount << "개 설치" << endl;

	// 정해진 수 이상 설치할 수 있었던 경우. 최소 거리를 늘려봐도 될 것 같음 (더 빡빡하게)
	if (deployCount >= C)
	{
		//cout << "성공" << endl;
		return true;
	}
	// 정해진 수 만큼 설치할 수 없었던 경우. 최소 거리를 줄여야 할 것 같음 (더 널널하게)
	else
	{
		//cout << "실패 " << endl;
		return false;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;

	pos.resize(N);
	for(int i=0;i<N;i++)
		cin >> pos[i];

	sort(pos.begin(), pos.end());

	// 매개변수 : 최소 거리
	int low = -1;
	int high = pos[N-1] - pos[0]+1;
	while (low + 1 < high)
	{
		int mid = (low + high) / 2;

		if (Check(low) == Check(mid))
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}

	//cout << "low : " << low << endl;
	//cout << "high : " << high << endl;

	cout << low;
}