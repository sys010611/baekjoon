#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define int long long

struct Info
{
	int t, a, h;
};

int N, H;
vector<Info> rooms;

bool Check(int maxHP)
{
	int currHP = maxHP;
	int currATK = H;

	for (auto room : rooms)
	{
		if (room.t == 1) // 몬스터
		{
			int numOfTurns = room.h / currATK;
			if(room.h % currATK > 0)
				numOfTurns++;

			int hitAmount = room.a * (numOfTurns - 1);
			if(hitAmount >= currHP)
				return false;

			currHP -= hitAmount;
		}
		else if (room.t == 2) // 포션
		{
			currHP += room.h;
			currHP = min(currHP, maxHP);

			currATK += room.a;
		}
	}

	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> H;
	rooms.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> rooms[i].t >> rooms[i].a >> rooms[i].h;
	}

	//이분탐색
	int lo = 1;
	int hi = 123456000000000000;
	if (Check(lo))
	{
		cout << lo;
		return 0;
	}
	while (lo + 1 < hi)
	{
		int mid = (lo + hi)/2;
		if (Check(lo) == Check(mid))
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	cout << hi;
	return 0;
}