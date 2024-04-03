#include <iostream>
#include <bitset>
#include <queue>
#include <tuple>
using namespace std;

int N, P;
int cost[16][16];
int dp[1<<16];

const int INF = 100000000;

int solve(int status)
{
	if (dp[status] != -1)
		return dp[status];

	// 다 켜진 경우
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if ((status & 1 << i) != 0)
			count++;
	}
	if (count >= P)
	{
		//cout << "모든 발전기 켜짐";
		return dp[status] = 0; //추가 비용은 0
	}

	// 다 켜지지 않은 경우
	dp[status] = INF;
	for (int i = 0; i < N; i++)
	{
		if ((status & 1 << i) == 0) // 안켜진 발전소 i 찾기
		{
			for (int j = 0; j < N; j++)
			{
				if ((status & 1 << j) != 0) //켜진 발전소 j를 찾아서, 그걸 이용해 i번 발전소를 켜기
				{
					dp[status] = min(dp[status], cost[j][i] + solve(status|1<<i));
				}
			}
		}
	}

	//cout << "status : " << bitset<3>(status) << endl;
	//cout << "dp " << bitset<3>(status) << " : " << dp[status] << endl;
	return dp[status];
}

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)	
		for(int j=0;j<N;j++)
			cin >> cost[i][j];

	for(int i=0;i<(1<<16);i++)
		dp[i] = -1;

	string status_str;
	cin >> status_str;

	cin >> P;

	int status = 0;
	for (int i = 0; i < status_str.length(); i++)
	{
		if (status_str[i] == 'Y')
		{
			status = status|1<<i;
		}
	}
	//cout << "init status : " << bitset<3>(status) << endl;

	int result = solve(status);
	if(result == INF)
		result = -1;
	cout << result;
}