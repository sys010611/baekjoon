#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int N, M;
int map[50][50];
bool visited[50][50];

int dRow[4] = {0, -1, 0, 1};
int dCol[4] = {-1, 0, 1, 0};

int maxComponentSize = 0;

bool valid(int row, int col)
{
	if(row < 0 || row >= M)
		return false;
	if(col<0 || col >= N)
		return false;
	if(visited[row][col])
		return false;
	
	return true;
}

// 컴포넌트의 크기 반환
int dfs(int row, int col)
{
	if (visited[row][col])
		return 0;

	visited[row][col] = true;
	//cout << row << ", " << col << " 방문 " << endl;

	int nodeCount = 1;

	int wallInfo = 15 - map[row][col]; // 비트를 뒤집는다. 
	//cout << "wallInfo: " << wallInfo << endl;


	if (wallInfo >= 8)
	{
		if (valid(row + 1, col))
		{
			nodeCount += dfs(row + 1, col);
		}
		wallInfo -= 8;
	}
	if (wallInfo >= 4)
	{
		if (valid(row, col + 1))
		{
			nodeCount += dfs(row, col + 1);
		}
		wallInfo -= 4;
	}
	if (wallInfo >= 2)
	{
		if (valid(row - 1, col))
		{
			nodeCount += dfs(row - 1, col);
		}
		wallInfo -= 2;
	}
	if (wallInfo >= 1)
	{
		if (valid(row, col - 1))
		{
			nodeCount += dfs(row, col - 1);
		}
		wallInfo -= 1;
	}

	return nodeCount;
}

// 컴포넌트의 개수 반환
int dfsAll()
{
	int componentCount = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				componentCount++;
				int componentSize = dfs(i, j);
				maxComponentSize = max(maxComponentSize, componentSize);
				//cout << "컴포넌트 탐색 종료" << endl;
				//cout << "크기 : " << componentSize << endl;
			}
		}
	}
	return componentCount;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	cout << dfsAll() << endl;
	cout << maxComponentSize << endl;

	maxComponentSize = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if(map[i][j] < (int)pow(2, k))
					break;

				map[i][j] -= (int)pow(2, k);
				fill(&visited[0][0], &visited[49][50], false);
				maxComponentSize = max(maxComponentSize, dfs(i, j));
				map[i][j] += (int)pow(2, k);
			}
		}
	}
	cout << maxComponentSize;
}