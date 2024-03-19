#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int,int> P;

int N, K, w, v;

int dp[101][100001];
vector<P> items;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, 0, sizeof(dp));

	cin >> N >> K;

	items.resize(N+1);
	for (int i = 1; i <= N; i++)
	{
		cin >> w >> v;

		items[i] = P(w, v);
	}

	for (int w = 1; w <= K; w++) // 배낭의 최대 무게를 1씩 증가시키면서 
	{
		for (int i = 1; i <= N; i++) // 물품을 하나씩 체크
		{
			int weight = items[i].first; 
			int value = items[i].second;

			if (weight > w) // 가방 용량보다 무거울 경우
			{
				dp[i][w] = dp[i-1][w]; //그냥 넣지 않음, 이전 상태 그대로
			}
			else
			{
				dp[i][w] = max(dp[i-1][w], value + dp[i-1][w - weight]); // 넣지 않거나, 넣고 가거나 둘 중 가치가 더 높은걸로
			}
		}
	}

	cout << dp[N][K];
}