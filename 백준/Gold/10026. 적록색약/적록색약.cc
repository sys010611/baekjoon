#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
char grid[100][100];
bool visited[100][100];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

typedef pair<int,int> P;

bool CheckValid(int row, int col)
{
	if(row < 0 || row >= n)
		return false;
	if(col < 0 || col >= n)
		return false;

	if(visited[row][col]) return false;

	return true;
}

bool isInPair(int row, int col, P pair)
{
	if(grid[row][col] == pair.first || grid[row][col] == pair.second)
		return true;
	else 
		return false;
}


void dfs(int currRow, int currCol, char targetChar)
{
	visited[currRow][currCol] = true;

	for (int i = 0; i < 4; i++)
	{
		if (CheckValid(currRow + dy[i], currCol + dx[i]) && grid[currRow + dy[i]][currCol + dx[i]] == targetChar)
		{
			dfs(currRow + dy[i], currCol + dx[i], targetChar);
		}
	}
}

void dfs(int currRow, int currCol, P targetChar)
{
	visited[currRow][currCol] = true;

	for (int i = 0; i < 4; i++)
	{
		if (CheckValid(currRow + dy[i], currCol + dx[i]) && isInPair(currRow + dy[i], currCol + dx[i], targetChar))
		{
			dfs(currRow + dy[i], currCol + dx[i], targetChar);
		}
	}
}

int dfsAll(int startRow, int startCol, P targetCharPair)
{
	memset(visited, false, sizeof(visited));
	int componentCount = 0;

	if (targetCharPair.first == targetCharPair.second)
	{
		char targetChar = targetCharPair.first;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] && grid[i][j] == targetChar)
				{
					componentCount++;
					dfs(i, j, targetChar);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if ((!visited[i][j] && isInPair(i,j, targetCharPair)))
				{
					componentCount++;
					dfs(i, j, targetCharPair);
				}
			}
		}
	}
	
	return componentCount;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> grid[i][j];

	//정상인이 봤을 때
	int normalRArea = dfsAll(0, 0, {'R','R'});
	int normalGArea = dfsAll(0, 0, {'G','G'});
	int normalBArea = dfsAll(0, 0, {'B','B'});

	//cout << normalRArea << " " << normalBArea << " " << normalGArea << endl;

	//색약이 봤을때
	int abnormalBothArea = dfsAll(0, 0, { 'R','G' });
	int abnormalBArea = dfsAll(0, 0, { 'B','B' });

	//cout << abnormalBothArea << " " << abnormalBArea << endl;

	cout << normalRArea+normalBArea+normalGArea << " " << abnormalBArea + abnormalBothArea;
}
