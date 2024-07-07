#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 100000000
#define MAX 2000

int C, N;
vector<pair<int,int>> infos; // 비용, 고객의 수
int dp[20][MAX];

int main()
{
	cin >> C >> N;

	for (int i = 0; i < N; i++)
	{
		int cost, count;
		cin >> cost >> count;
		infos.push_back({cost, count});
	}

	fill(&dp[0][0], &dp[19][MAX], INF);

	//base case
	// 0명을 모으는 비용 = 0;
	for (int i = 0; i < N; i++)
	{
		dp[i][0] = 0;
	}
	// 첫번째 정보에 한해서 먼저 계산 
	int cost = infos[0].first;
	int count = infos[0].second;
	for (int i = 1; i < MAX; i++)
	{
		if (i % count != 0)
		{
			dp[0][i] = INF;
		}
		else
		{
			dp[0][i] = i/count * cost;
		}
	}

	for (int i = 1; i < N; i++) // 정보의 idx
	{
		int cost = infos[i].first;
		int count = infos[i].second;

		for (int j = 1; j < MAX; j++) // 모을 사람 수
		{
			if(count > j)
				dp[i][j] = dp[i-1][j];
			else
			{
				dp[i][j] = min(dp[i-1][j], dp[i][j-count] + cost);
			}
		}
	}

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j <= C; j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	auto result = min_element(&dp[N-1][C], &dp[N-1][MAX]);

	cout << *result;
}