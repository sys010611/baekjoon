#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[300][300]; //각 칸의 방문 여부
queue<pair<int,int>> Q;
int dx[8] = {2,2,1,1,-2,-2,-1,-1};
int dy[8] = {1,-1,2,-2,1,-1,2,-2}; //나이트의 이동

int bfs(int startX, int startY, int endX, int endY, int l);

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int l; //체스판의 크기: L x L
		cin >> l;
		int startX,startY,endX,endY; //시작점과 도착점의 좌표
		cin >> startX >> startY;
		cin >> endX >> endY;

		for (int i = 0; i < 300; i++)
		{
			for (int j = 0; j < 300; j++)
			{
				visited[i][j] = false; //방문 여부 초기화
			}
		}
		Q = queue<pair<int, int>>();
		cout << bfs(startX, startY, endX, endY, l) << endl;
	}
}

int bfs(int startX, int startY, int endX, int endY, int l)
{
	visited[startX][startY] = true;
	Q.push({startX, startY}); //시작점을 방문, 큐에 push

	if (startX == endX && startY == endY) //시작점과 도착점이 같을 경우
	{
		return 0;
	}

	int level = 0;
	while (true)
	{
		int qSize = Q.size();
		while (qSize--)
		{
			//cout << "현재 레벨: " << level << endl;
			int currentX = Q.front().first;
			int currentY = Q.front().second;
			Q.pop();

			for (int i = 0; i < 8; i++)
			{
				int nextX = currentX + dx[i];
				int nextY = currentY + dy[i];
				if (nextX == endX && nextY == endY) //도착점을 찾았을 경우
				{
					return level+1;
				}
				if (!visited[nextX][nextY] && nextX < l && nextX >= 0 && nextY < l && nextY >= 0) //방문한적 없음, 좌표가 체스판의 범위 안에 있을 경우
				{
					Q.push({nextX, nextY});
					visited[nextX][nextY] = true;
					//cout << nextX << ", " << nextY << " 방문" << endl;
				}
			}
		}
		level++;
	}
}