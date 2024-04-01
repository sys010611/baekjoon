#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <bitset>
using namespace std;

int N;
pair<int, int> position[16];
double W[16][16];
double dp[16][1 << 16];

const int INF = 100000000;

double getDist(pair<int, int> p1, pair<int, int> p2)
{
	return sqrt(pow((double)p1.first - p2.first, 2) + pow((double)p1.second - p2.second, 2));
}

/// <summary>
/// curr에서 순회 종료까지의 최단거리 리턴.
/// </summary>
double TSP(int curr, int visited)
{
	//cout << "Curr: " << curr << endl;
	//cout << "Visited: " << bitset<8>(visited) << endl;

	if (dp[curr][visited] != -1)
	{
		return dp[curr][visited];
	}


	if (visited == (1 << N) - 1) // 모든 도시를 방문한 경우 (base case)
	{
		return dp[curr][visited] = W[curr][0];
	}

	//아직 현재 위치에서의 최단거리가 정해지지 않은 경우
	dp[curr][visited] = INF;
	for (int i = 0; i < N; i++) // 방문하지 않은 다른 도시 방문 시도
	{
		if ((visited & (1 << i)) == 0) // not visited
		{
			dp[curr][visited] = min(dp[curr][visited], W[curr][i] + TSP(i, visited | 1 << i));
		}
	}
	// 다른 도시로 한번씩 다 가본 것 중 최소 결과값을 리턴.
	return dp[curr][visited];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	cout << fixed;
	cout.precision(10);

	for (int i = 0; i < 16; i++)
		for (int j = 0; j < (1 << 16); j++)
			dp[i][j] = -1;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> position[i].first >> position[i].second;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			W[i][j] = getDist(position[i], position[j]);
		}
	}

	cout << TSP(0, 1);
}



