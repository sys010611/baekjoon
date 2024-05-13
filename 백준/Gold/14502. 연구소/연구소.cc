#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int map[8][8];
int n,m;

int dRow[4] = {0,-1,0,1};
int dCol[4] = {1,0,-1,0};

int result = 0;

int BFS()
{
	bool visited[8][8];
	fill(&visited[0][0], &visited[7][8], false);

	vector<pair<int,int>> virusPos;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(map[i][j] == 2)
				virusPos.push_back({i,j});
		}
	}

	queue<pair<int,int>> Q;

	for (auto& pos : virusPos)
	{
		Q.push(pos);
		visited[pos.first][pos.second] = true;
	}

	while (!Q.empty())
	{
		auto curr = Q.front(); Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nRow = curr.first + dRow[i];
			int nCol = curr.second + dCol[i];

			if(nRow < 0 || nRow >= n || nCol < 0 || nCol >= m || visited[nRow][nCol] || map[nRow][nCol] == 1)
				continue;

			visited[nRow][nCol] = true;
			map[nRow][nCol] = 2;

			Q.push({nRow,nCol});
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(map[i][j] == 0)
				result++;
		}
	}


	//원상복구
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 2)
			{
				map[i][j] = 0;
			}
		}
	}
	for (auto pos : virusPos)
	{
		map[pos.first][pos.second] = 2;
	}

	//cout << "안전구역 범위 : " << result << endl;
	return result;
}

void backtrack(int row, int col, int depth)
{
	//cout << row << " , " << col << " 에 벽을 세웠음 " << endl;

	if (depth == 3) // 벽 3개를 다 세웠을 경우
	{
		//cout << "벽 3개를 모두 세움, 확산 수행" << endl;

		//확산, 안전 영역 검사
		result = max(result, BFS());

		return;
	}

	// 마저 벽을 세워야 할 경우
	for (int i = row; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(i == row && j <= col) continue; //이미 세웠던 곳 에 또 세우는 경우 막기

			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				backtrack(i,j,depth+1);
				map[i][j] = 0;
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				backtrack(i, j, 1);
				map[i][j] = 0;
			}
		}
	}

	cout << result;
}