#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> triangle;
int dp[500][500];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	triangle.resize(n);

	int input;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> input;
			triangle[i].push_back(input);
		}
	}

	/*cout << "입력 확인" << endl;
	for (int i = 0; i < n; i++)
	{
		for (auto it = triangle[i].begin(); it != triangle[i].end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}*/

	for(int i=0;i<500;i++)
		for(int j=0;j<500;j++)
			dp[i][j] = 0;

	//base case
	dp[0][0] = triangle[0][0];

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = dp[i-1][0] + triangle[i][0];

		for (int j = 1; j < i; j++)
		{
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
		}

		dp[i][i] = dp[i-1][i-1] + triangle[i][i];
	}

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/


	cout << *max_element(dp[n-1], dp[n-1]+n);
}