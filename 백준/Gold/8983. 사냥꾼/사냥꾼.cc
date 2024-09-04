#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define int long long

int M, N, L;

vector<int> shootPos;
vector<pair<int,int>> animals;
vector<int> animalDist;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N >> L;

	shootPos.resize(M);
	for (int i = 0; i < M; i++)
	{
		cin >> shootPos[i];
	}
	sort(shootPos.begin(), shootPos.end());

	animals.resize(N);
	animalDist.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> animals[i].first >> animals[i].second;
	}

	// 각 동물까지의 거리 구하기
	for (int i=0;i<animals.size();i++)
	{
		auto& animal = animals[i];

		int dist = 0;
		dist += animal.second;

		// x거리는 이분탐색으로 구하기
		auto lb = lower_bound(shootPos.begin(), shootPos.end(), animal.first);
		if(lb == shootPos.begin())
			dist += abs(*lb - animal.first);
		else if (lb == shootPos.end())
			dist += abs(*(shootPos.end() - 1) - animal.first);
		else
		{
			int xDist1 = *lb - animal.first;
			int xDist2 = animal.first - *(lb-1);
			dist += min(xDist1, xDist2);
		}

		animalDist[i] = dist;
	}
	sort(animalDist.begin(), animalDist.end());

	//for (auto dist : animalDist)
	//{
	//	cout << dist << " ";
	//}
	//cout << endl;

	// 현재 사정거리로 upper bound 한 인덱스가 곧 잡을 수 있는 동물 수
	auto ub = upper_bound(animalDist.begin(), animalDist.end(), L);

	signed result = (ub - animalDist.begin());

	cout << result;
}