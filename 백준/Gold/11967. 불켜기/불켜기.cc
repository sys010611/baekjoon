#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> P;

int dRow[4] = {0, -1, 0, 1};
int dCol[4] = {1, 0, -1, 0};

int N, M;
vector<P> adjList[101][101];
bool isLightOn[101][101];
int ret = 1;
bool visited[101][101];

void InitVisitedArr()
{
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			visited[i][j] = false;	
}

void BFS()
{
	InitVisitedArr();

	queue<P> Q;
	visited[1][1] = true;
	Q.push(P(1,1));

	while (!Q.empty())
	{
		P curr = Q.front(); Q.pop();
		//printf("(%d, %d)\n", curr.first, curr.second);
		
		// 현재 방에 있는 스위치 사용
		bool usedLight = false;
		for (P nextRoom : adjList[curr.first][curr.second])
		{
			if (!isLightOn[nextRoom.first][nextRoom.second])
			{
				isLightOn[nextRoom.first][nextRoom.second] = true;
				//printf("%d, %d 방 불 켜짐\n", nextRoom.first, nextRoom.second);
				usedLight = true;
				ret++;

				for (int i = 0; i < 101; i++)
					for (int j = 0; j < 101; j++)
						visited[i][j] = false;
			}
		}
		if (usedLight)
		{
			InitVisitedArr();
			Q = queue<P>();
		}

		// 상하좌우로 이동
		for (int i = 0; i < 4; i++)
		{
			int nRow = curr.first + dRow[i];
			int nCol = curr.second + dCol[i];
			if(nRow < 1 || nCol < 1 || nRow > N || nCol > N)
				continue;
			if(visited[nRow][nCol] || !isLightOn[nRow][nCol])
				continue;

			visited[nRow][nCol] = true;
			Q.push(P(nRow, nCol));
		}
	}
}

signed main()
{
	memset(isLightOn, 0, sizeof(isLightOn));
	isLightOn[1][1] = true;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int x,y,a,b;
		cin >> x >> y >> a >> b;
		adjList[x][y].push_back(P(a,b));
	}

	BFS();
	cout << ret;
}
