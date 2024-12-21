#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#include <numeric>
#include <cstring>
using namespace std;

int dRow[] = { 0, -1, 0, 1 };
int dCol[] = { 1, 0, -1, 0 };

int N, M;
int grid[101][101];
bool visited[101][101];
bool isToMelt[101][101];

// 빈 칸마다 외부 연결 여부 확인
void DFS(int currRow, int currCol)
{
	//printf("%d, %d\n", currRow, currCol);

	visited[currRow][currCol] = true;

	for (int i = 0; i < 4; i++)
	{
		int nRow = currRow + dRow[i];
		int nCol = currCol + dCol[i];

		if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= M)
		{
			continue;
		}

		if (grid[nRow][nCol] == 0 && !visited[nRow][nCol])
		{
			DFS(nRow, nCol);
		}
	}
}

void MeltCheeses()
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			if (grid[row][col] == 1 && isToMelt[row][col])
			{
				grid[row][col] = 0;
			}
		}
	}
}


void CheckCheeseIfShouldMelt()
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			if (grid[row][col] == 1)
			{
				int contactCount = 0;
				for (int k = 0; k < 4; k++)
				{
					int nRow = row + dRow[k];
					int nCol = col + dCol[k];

					// 치즈이므로 out of range 걱정 x
					if (grid[nRow][nCol] == 0 && visited[nRow][nCol] == true)
					{
						contactCount++;
					}
				}

				if (contactCount >= 2)
				{
					isToMelt[row][col] = true;
				}
			}
		}
	}
}

bool CheckIfAllMelted()
{
	bool allMelted = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == 1)
			{
				allMelted = false;
			}
		}
	}
	return allMelted;
}

void Print()
{
	cout << "===============" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << "===============" << endl;
}

signed main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
		}
	}

	for (int t = 1; ; t++)
	{
		memset(visited, 0, sizeof(visited));
		memset(isToMelt, 0, sizeof(isToMelt));

		DFS(0,0);

		CheckCheeseIfShouldMelt();

		MeltCheeses();

		//Print();


		if (CheckIfAllMelted())
		{
			cout << t;
			return 0;
		}
		else
			continue;
	}
}

