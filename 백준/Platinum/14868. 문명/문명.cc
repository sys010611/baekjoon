#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int N, K;
int map[2000][2000];
int p[4000001]; // 각 문명의 부모 정보.
queue<pair<int, int>> unionQ;
queue<pair<int, int>> bfsQ;

int find(int n)
{
	if (p[n] == -1)
		return n;
	else
		return p[n] = find(p[n]);
}

void Merge(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);

	p[rootB] = rootA;
}

void MergeAll()
{
	while (!unionQ.empty())
	{
		int currX = unionQ.front().first;
		int currY = unionQ.front().second;

		bfsQ.push(unionQ.front());
		unionQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = currX + dx[i];
			int nextY = currY + dy[i];

			//범위 밖이거나, 인접 칸이 문명이 아니었을 경우 그냥 빠져나오기
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || map[nextX][nextY] == 0)
				continue;

			int civilA = map[currX][currY];
			int civilB = map[nextX][nextY];

			if (find(civilA) != find(civilB))
			{
				Merge(civilA, civilB);
				K--;
			}
		}
	}
}

void BFS()
{
	while (!bfsQ.empty())
	{
		int currX = bfsQ.front().first;
		int currY = bfsQ.front().second;

		bfsQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = currX + dx[i];
			int nextY = currY + dy[i];

			//범위 밖이거나, 인접 칸이 문명이었을 경우 그냥 빠져나오기
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || map[nextX][nextY] != 0)
				continue;

			map[nextX][nextY] = map[currX][currY];
			unionQ.push({ nextX, nextY });
		}
	}
}

int main()
{
	cin >> N >> K;

	fill(p, p + 4000001, -1);

	int civilNo = 1;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		map[x][y] = civilNo++;
		unionQ.push({ x,y });
	}

	MergeAll();
	int result = 0;
	while (true)
	{
		if (K == 1)
		{
			cout << result;
			return 0;
		}

		BFS();
		MergeAll();

		result++;
	}
}