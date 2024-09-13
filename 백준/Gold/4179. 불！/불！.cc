#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dRow[4] = { 0, -1, 0, 1 };
int dCol[4] = { 1, 0, -1, 0 };

int R, C;
char grid[1000][1000];
typedef pair<int,int> P;

queue<P> fireQ;
queue<P> playerQ;

void fire()
{
	int qSize = fireQ.size();
	while (qSize--)
	{
		P curr = fireQ.front(); fireQ.pop();

		int row = curr.first;
		int col = curr.second;

		for (int i = 0; i < 4; i++)
		{
			int nRow = row + dRow[i];
			int nCol = col + dCol[i];

			if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
				continue;
			if (grid[nRow][nCol] != '.' && grid[nRow][nCol] != 'J')
				continue;

			grid[nRow][nCol] = 'F';
			fireQ.push({nRow, nCol});
		}
	}
}

bool player()
{
	int qSize = playerQ.size();
	if (qSize == 0)
	{
		cout << "IMPOSSIBLE";
		exit(0);
	}

	while (qSize--)
	{
		P curr = playerQ.front(); playerQ.pop();

		int row = curr.first;
		int col = curr.second;

		for (int i = 0; i < 4; i++)
		{
			int nRow = row + dRow[i];
			int nCol = col + dCol[i];

			if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
			{
				return true;
			}
			if (grid[nRow][nCol] != '.')
				continue;

			grid[nRow][nCol] = 'J';
			playerQ.push({nRow, nCol});
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char input; cin >> input;
			grid[i][j] = input;
			if (input == 'J')
				playerQ.push({ i,j });
			if (input == 'F')
				fireQ.push({ i,j });
		}
	}

	for (int t = 1; ; t++)
	{
		fire();

		if (player())
		{
			cout << t;
			return 0;
		}

		//cout << "t :" << t << endl;
		//for (int i = 0; i < R; i++)
		//{
		//	for (int j = 0; j < C; j++)
		//	{
		//		cout << grid[i][j];
		//	}
		//	cout << endl;
		//}
		//cout << endl;
	}
}