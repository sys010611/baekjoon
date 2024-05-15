#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

int N, K;
int seq[100];
set<int> plugs;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> seq[i];
	}

	int count = 0;

	for (int i = 0; i < K; i++)
	{
		//cout << "현재 멀티탭 현황 : ";
		//for(auto plug : plugs)	cout << plug << " ";
		//cout << endl;

		//cout << "현재 꽂는 플러그 : " << seq[i] << endl;

		if (plugs.find(seq[i]) != plugs.end()) // 이미 꽂혀있었을 경우
		{
			continue; 
		}

		// 새로 꽂아야 하는 경우
		if (plugs.size() < N) // 빈 공간이 있을 때는 그냥 꼽으면 됨
		{
			plugs.insert(seq[i]);
			continue;
		}

		// 빈 공간이 없을 경우. 가장 나중에 쓸 플러그를 제거
		int leastSoonPlug = *plugs.begin(); // 가장 나중에 쓰는 플러그
		int timeUntilNextUse_max = -1; // 가장 나중에 쓰는 플러그의 꽂기까지의 시간
		for (auto plug : plugs)
		{
			int timeUntilNextUse = 10000000;

			bool found = false; // 뒤에 쓰는 경우가 찾아졌는지 여부
			for (int j = i+1; j < K; j++)
			{
				if (seq[j] == plug)
				{
					found = true;
					timeUntilNextUse = j - i;
					if (timeUntilNextUse_max < timeUntilNextUse)
					{
						leastSoonPlug = plug;
						timeUntilNextUse_max = timeUntilNextUse;
					}
					//cout << plug << " : " << timeUntilNextUse << " 뒤에 사용 " << endl;
					break;
				}
			}
			if (!found) // 뒤에 쓸일이 없는 플러그 발견. 그걸 제거
			{
				timeUntilNextUse_max = timeUntilNextUse;
				leastSoonPlug = plug;
				//cout << plug << " : " << " 더 이상 사용하지 않음 " << endl;
			}
		}

		//cout << leastSoonPlug << " 를 제거 " << endl;
		plugs.erase(leastSoonPlug);
		count++;
		plugs.insert(seq[i]);
	}

	cout << count;
}