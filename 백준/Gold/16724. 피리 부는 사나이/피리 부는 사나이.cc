#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int,int> P;

int N, M;
char grid[1000][1000];
int compNo[1000][1000];
bool visited[1000][1000];

int currCompNo = 0;

int DFS(int row, int col)
{
	visited[row][col] = true;

	int nextRow = row;
	int nextCol = col;

	switch (grid[row][col])
	{
		case 'U':	
			nextRow--;
			break;
		case 'D':
			nextRow++;
			break;
		case 'L':
			nextCol--;
			break;
		case 'R':
			nextCol++;
			break;
	}

	if (visited[nextRow][nextCol])
	{
		if (compNo[nextRow][nextCol] == -1)
		{
			currCompNo++;
			return compNo[row][col] = currCompNo;
		}
		else
		{
			return compNo[row][col] = compNo[nextRow][nextCol];
		}
	}

	return compNo[row][col] = DFS(nextRow, nextCol);
}

void DFSAll()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visited[i][j])
			{
				DFS(i, j);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(compNo, -1, sizeof(compNo));
	memset(visited, 0, sizeof(visited));

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
		}
	}

	DFSAll();

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		cout << compNo[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cout << currCompNo;
}