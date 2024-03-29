#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

const int INF = 100000000;

int N;
int W[16][16];
int dp[16][1<<16]; //[현재 노드][방문 현황]일 때 최단 루트 거리

/// <summary>
/// curr : 현재 노드 visited : 도시 방문 현황
/// </summary>
int TSP(int curr, int visited)
{
	//cout << "curr : " << curr << endl;
	//cout << "visited : " << bitset<8>(visited) << endl;
	
	if(dp[curr][visited] != -1)
		return dp[curr][visited];

	//base case
	if (visited == (1 << N) - 1) // 모든 도시를 방문한 상태일 경우.
	{
		if (W[curr][0] != 0) // 시작 지점으로 돌아갈 수 있다면
		{
			//cout << "시작 지점 복귀 가능" << endl;
			return dp[curr][visited] = W[curr][0]; // 바로 그 거리 리턴
		}
		else
		{
			return dp[curr][visited] = INF; // 아니면 그 루트는 못가는 것.
		}
	}

	// 다른 도시를 하나씩 방문.
	dp[curr][visited] = INF;
	for (int i = 0; i < N; i++)
	{
		if ((visited & (1 << i)) == 0 && W[curr][i] != 0) // i번 도시를 아직 방문하지 않았고, 현재 도시에서 갈 수 있는 경우
		{
			dp[curr][visited] = min(dp[curr][visited], W[curr][i] + TSP(i, visited | 1<<i));
		}
	}

	//cout << "dp[curr][visited] : " << dp[curr][visited] << endl;
	return dp[curr][visited];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=0;i<16;i++)
		for (int j = 0; j < (1 << 16); j++)
			dp[i][j] = -1;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> W[i][j];
		}
	}

	cout << TSP(0, 1);
}