#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int map[500][500];
int dp[500][500];
int hasRoute[500][500];

int dRow[] = {0,1,0,-1};
int dCol[] = {1,0,-1,0};

int M, N;

void PrintDP()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int DFS(int currRow, int currCol)
{
	if (dp[currRow][currCol] != 0) // 이미 루트가 개척되어 있었다면 굳이 더 안들어감
	{
		return dp[currRow][currCol]; // 돌아가면서 dp += 앞단계 루트 수
	}

	//이외의 경우: 이어서 DFS
	int routeCount = 0; // 앞으로 더 들어갔을 때 루트의 경우의 수의 합.
	for (int i = 0; i < 4; i++)
	{
		int nextRow = currRow + dRow[i];
		int nextCol = currCol + dCol[i];

		if (nextRow >= 0 && nextRow < M && nextCol >= 0 && nextCol < N) // 인덱스 범위 확인
		{
			if (!hasRoute[nextRow][nextCol]) // 길이 없다면 굳이 가지 않음.
				continue;
			
			if (map[nextRow][nextCol] > map[currRow][currCol])
			{
				routeCount += DFS(nextRow, nextCol);
			}
		}
	}

	if (routeCount == 0) //dfs 갔다와도 수확이 없다 = 길이 없다.
	{
		hasRoute[currRow][currCol] = false;
	}

	return dp[currRow][currCol] = routeCount;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, 0, sizeof(dp));
	fill(&hasRoute[0][0], &hasRoute[499][500], true);
	dp[0][0] = 1; //base case;			

	cin >> M >> N;

	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			cin >> map[i][j];

	cout << DFS(M-1, N-1);
}