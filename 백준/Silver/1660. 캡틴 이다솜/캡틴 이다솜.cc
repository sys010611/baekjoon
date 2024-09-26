#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define INF 100000000

int N;

vector<int> triangles;
vector<int> tetras;

int dp[300001];

int triangleSizeThreshold = 200000;

int GetTetraCount(int ballCount)
{
	for (int i = 1; i <= ballCount; i++)
	{		
		for (auto tetra : tetras)
		{
			if (tetra < i)
			{
				dp[i] = min(dp[i], dp[i - tetra] + dp[tetra]);
			}
			else
				break;
		}
	}

	return dp[ballCount];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	
	int currTriangle = 1;
	for (int addingNum = 2;; addingNum++)
	{
		triangles.push_back(currTriangle);
		currTriangle += addingNum;

		if(currTriangle > triangleSizeThreshold)
			break;
	}

	int currTetra = 0;
	for (int i = 0; i < triangles.size(); i++)
	{
		currTetra += triangles[i];
		if(currTetra >= 300001) 
			break;

		tetras.push_back(currTetra);
	}

	fill(dp, dp + 300001, INF);

	for (auto tetra : tetras)
	{
		//cout << tetra << " ";
		dp[tetra] = 1;
	}

	cout << GetTetraCount(N);
}