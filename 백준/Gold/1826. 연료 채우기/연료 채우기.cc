#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> P;

priority_queue<P> PQ; // <충전량, 위치>

int N, L, currFuel;
vector<P> stations; // <위치, 충전량>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	stations.resize(N);
	for (int i = 0; i < N; i++)
	{
		int a,b;
		cin >> a >> b;
		stations[i] = P(a, b);
	}

	cin >> L >> currFuel;

	int currPos = 0;
	sort(stations.begin(), stations.end()); // 가까운 순으로 정렬

	int result = 0;
	for (int i=0;i<N;i++)
	{
		P station = stations[i];
		//printf("station : 위치 %d, 충전량 %d\n", station.first, station.second);

		if (currFuel >= L - currPos)
		{
			cout << result;
			return 0;
		}

		int pos = station.first;
		int amount = station.second;

		if (pos - currPos <= currFuel) // 갈 수 있는 곳이라면
		{
			//cout << "도달 가능, PQ에 push" << endl;
			PQ.push(P(amount, pos));
			continue;
		}
		else // 이 다음 주유소는 도달하지 못하는 경우. PQ에 있는 주유소 중 하나에 들러서 충전해야 함
		{
			if (PQ.empty())
			{
				cout << -1;
				return 0;
			}

			P nextStation = PQ.top(); PQ.pop(); // 가장 많이 충전 가능한 주유소로
			
			int nextPos = nextStation.second;
			int chargeAmount = nextStation.first;

			//printf("%d 에서 %d 충전\n", nextPos, chargeAmount);

			currFuel -= (nextStation.second - currPos);
			currFuel += nextStation.first;
			//cout << "현재 연료 : " << currFuel << endl;

			currPos = nextStation.second;
			//cout << "현재 위치 : " << currPos << endl;

			result++;
			i--;
			continue;
		}
	}
	while (!PQ.empty())
	{
		P nextStation = PQ.top(); PQ.pop(); // 가장 많이 충전 가능한 주유소로

		int nextPos = nextStation.second;
		int chargeAmount = nextStation.first;

		//printf("%d 에서 %d 충전\n", nextPos, chargeAmount);

		currFuel -= (nextStation.second - currPos);
		currFuel += nextStation.first;
		//cout << "현재 연료 : " << currFuel << endl;

		currPos = nextStation.second;
		//cout << "현재 위치 : " << currPos << endl;

		result++;

		if (currFuel >= L - currPos)
		{
			cout << result;
			return 0;
		}
	}




	cout << -1;
}