#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

char map[600][600];
bool visited[600][600];

typedef pair<int,int> P;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n,m;

bool IsMovable(int row, int col)
{
	if(row < 0 || row >= n) return false;
	if(col < 0 || col >= m) return false;
	if(visited[row][col]) return false;
	if(map[row][col] == 'X') return false;

	return true;
}

int bfs(int startRow, int startCol)
{	
	queue<P> Q;
	int count = 0;

	memset(visited, false, sizeof(visited));

	visited[startRow][startCol] = true;
	Q.push({startRow, startCol});

	while (!Q.empty())
	{
		P curr = Q.front(); Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextRow = curr.first + dy[i];
			int nextCol = curr.second + dx[i];

			if (IsMovable(nextRow, nextCol))
			{
				if (map[nextRow][nextCol] == 'P')
				{
					count++;
				}

				visited[nextRow][nextCol] = true;
				//cout << nextRow << " " << nextCol << " visited" << endl;
				Q.push({nextRow, nextCol});
			}
		}
	}

	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int startRow, startCol;

	char input;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> input;
			map[i][j] = input;
			if (input == 'I')
			{
				startRow = i; startCol = j;
			}
		}
	}

	int result = bfs(startRow, startCol);

	if(result == 0) cout << "TT";
	else cout << result;

}
