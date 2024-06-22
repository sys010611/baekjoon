#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;

int dRow[4] = {0, -1, 0, 1};
int dCol[4] = {1, 0, -1, 0};

int N, M;
int board[1000][1000];
int componentLabel[1000][1000];
typedef pair<int,int> P;

bool visited[1000][1000];
map<int, int> componentSize;

int dfs(int row, int col, int componentIdx)
{
	int visitedNodeCount = 1;
	visited[row][col] = true;
	componentLabel[row][col] = componentIdx;

	for (int i = 0; i < 4; i++)
	{
		int nRow = row+dRow[i];
		int nCol = col+dCol[i];

		if(nRow<0||nRow>=N||nCol<0||nCol>=M)
			continue;

		if(visited[nRow][nCol] || board[nRow][nCol] == 1)
			continue;

		visitedNodeCount += dfs(nRow, nCol, componentIdx);
	}

	return visitedNodeCount;
}

void dfsAll()
{
	int currComponentIdx = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if(visited[i][j] || board[i][j] == 1)
				continue;

			int currComponentSize = dfs(i, j, currComponentIdx);

			componentSize[currComponentIdx++] = currComponentSize;
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = line[j] - '0';
		}
	}

	dfsAll();

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		cout << componentLabel[i][j]<< " ";
	//	}
	//	cout<<endl;
	//}

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			if (board[row][col] == 0)
			{
				cout<<0;
			}
			else if (board[row][col] == 1)
			{
				int movablesCount = 1;

				set<int> visitedComponents;

				for (int i = 0; i < 4; i++)
				{
					int nRow = row+dRow[i];
					int nCol = col+dCol[i];

					if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= M)
						continue;

					int currLabel = componentLabel[nRow][nCol];

					if (visitedComponents.find(currLabel) == visitedComponents.end())
					{
						visitedComponents.insert(currLabel);
						movablesCount += componentSize[currLabel];
					}
					else
						continue;
					
				}
				cout<<movablesCount%10;
			}
		}
		cout<<endl;
	}
}