#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1}; 
int map[1000][1000];
int visited[1000][1000]; //방문여부(익었는지 여부)
queue<pair<int,int>> Q;

int bfs(int col, int row)
{
	for (int i = 0; i < row; i++) //처음 익은 토마토들의 좌표를 큐에 저장, 방문여부 true
	{
		for (int j = 0; j < col; j++)
		{
			if (map[i][j] == 1)
			{
				Q.push({i,j});
				visited[i][j] = true;
			}
		}
	}
	int level = 0;
	int currCol,currRow,nextCol,nextRow;

	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			currRow = Q.front().first;
			currCol = Q.front().second;
			Q.pop();
			//cout << "현재 익은 토마토의 좌표: " << currRow << " " << currCol << endl;

			for (int i = 0; i < 4; i++)
			{
				nextRow = currRow + dy[i];
				nextCol = currCol + dx[i];
				if (map[nextRow][nextCol] != -1 && !visited[nextRow][nextCol]) //빈 공간이 아님, 방문한적 없음
				{
					if (nextRow < row && nextRow >= 0 && nextCol < col && nextCol >= 0) //범위 안
					{
						Q.push({ nextRow,nextCol });
						visited[nextRow][nextCol] = true;
						//cout << "익을 토마토의 좌표: " << nextRow << " " << nextCol << endl;
					}
				}
			}
		}
		level++;
	}

	for (int i = 0; i < row; i++) //안 익은 토마토가 있을 시 -1 리턴
	{
		for (int j = 0; j < col; j++)
		{
			if (!visited[i][j] && map[i][j] != -1)
			{
				return -1;
			}
		}
	}
	return level-1;
}

int main()
{
	int col,row;
	cin >> col >> row;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			visited[i][j] = false;
		}
	}

	cout << bfs(col, row);
}