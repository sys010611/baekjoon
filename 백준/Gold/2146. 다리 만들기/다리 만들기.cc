#include <iostream>
#include <queue>
#include <unordered_set>
#include <cstring>
#include <cassert>
#include <climits>
using namespace std;

int dRow[] = { 0, -1, 0, 1 };
int dCol[] = { 1, 0, -1, 0 };

int N;
int grid[100][100];
bool visited[100][100];
int currCompNo = 1;

void PrintMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

void DFS(int cRow, int cCol)
{
	visited[cRow][cCol] = true;
	grid[cRow][cCol] = currCompNo;

	for (int i = 0; i < 4; i++)
	{
		int nRow = cRow + dRow[i];
		int nCol = cCol + dCol[i];

		if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
		{
			continue;
		}
		if (grid[nRow][nCol] == 1 && !visited[nRow][nCol])
		{
			DFS(nRow, nCol);
		}
	}
}

int BFS(int startRow, int startCol)
{
	memset(visited, 0, sizeof(visited));

	//printf("%d, %d 에서 시작 \n", startRow, startCol);

	int dist1 = -1;
	int dist2 = -1;

	unordered_set<int> visitedComp;

	queue<pair<int, int>> Q;

	Q.push({ startRow, startCol });
	visited[startRow][startCol] = true;

	int level = 0;
	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			int cRow = Q.front().first;
			int cCol = Q.front().second;
			Q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nRow = cRow + dRow[i];
				int nCol = cCol + dCol[i];

				if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N || visited[nRow][nCol])
					continue;

				if (grid[nRow][nCol] != 0)
				{
					int foundCompNo = grid[nRow][nCol];
					if (visitedComp.find(foundCompNo) == visitedComp.end())
					{
						if (dist1 == -1)
						{
							dist1 = level;
						}
						else
						{
							dist2 = level;
							
							//cout << "결과 : " << endl;
							//cout << "dist1 : " << dist1 << endl;
							//cout << "dist2 : " << dist2 << endl;

							return dist1 + dist2 + 1;
						}

						visitedComp.insert(grid[nRow][nCol]);
					}

					continue;
				}

				Q.push({ nRow, nCol });
				visited[nRow][nCol] = true;
			}
		}
		level++;
	}
	return INT_MAX;
}

signed main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> grid[i][j];
		}
	}

	// 컴포넌트 번호 붙이기
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j] == 1 && !visited[i][j])
			{
				DFS(i, j);
				currCompNo++;
			}
		}
	}

	//PrintMap();

	int result = INT_MAX;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j] == 0)
			{
				result = min(result, BFS(i, j));
			}
		}
	}

	cout << result;
}
