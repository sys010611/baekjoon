#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num[100000];
int dp[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for(int i=0;i<n;i++)
		cin >> num[i];

	//base case
	dp[0] = num[0];

	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i-1] + num[i], num[i]); //이전까지의 합을 가져갈지, 버릴지 선택
	}

	cout << *max_element(dp, dp+n);
}