#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<int> arr;

int S, E;
int dp[2001][2001];

int Check(int start, int end)
{
	if(dp[start][end] != -1)
		return dp[start][end];

	if (end - start == 1)
	{
		if (arr[end] == arr[start])
			return dp[start][end] = 1;
		else
			return dp[start][end] = 0;
	}

	//여기서부터는 숫자 3개 이상

	if(arr[start] != arr[end])
		return dp[start][end] = 0;
	else // 양끝 숫자가 같음, 이제 안쪽만 확인하면 됨
	{
		if (Check(start+1, end-1))
			return dp[start][end] = 1;
		else
			return dp[start][end] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	for(int i=0;i<2001;i++)
		dp[i][i] = 1;

	cin >> N;
	arr.resize(N+1);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> S >> E;

		cout << Check(S,E) << "\n";
	}
}