#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool visited[1000001];
queue<int> Q;

int bfs(int f, int s, int g, int u, int d)
{
	int level = 0;
	int currentFloor = -1;
	visited[s] = true;
	Q.push(s);
	//cout << s << "층 시작" << endl;

	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			currentFloor = Q.front();
			Q.pop();
			if (currentFloor == g)
			{
				return level;
			}

			if (currentFloor + u <= f && !visited[currentFloor + u]) //위로 올라갔을때 범위 안이고 방문한적 없을 경우
			{
				Q.push(currentFloor + u);
				visited[currentFloor + u] = true;
				//cout << currentFloor+u <<"층으로 이동 가능" << endl;
			}
			if (currentFloor - d > 0 && !visited[currentFloor - d]) //아래로
			{
				Q.push(currentFloor - d);
				visited[currentFloor - d] = true;
				//cout << currentFloor -d << "층으로 이동 가능" << endl;
			}
		}
		level++;
	}
	return -1;
}

int main()
{
	int f,s,g,u,d;
	cin >> f >> s >> g >> u >> d;
	for (int i = 0; i < 1000001; i++)
	{
		visited[i] = false;
	}
	int result = bfs(f,s,g,u,d);
	if (result == -1)
	{
		cout << "use the stairs";
	}
	else
	{
		cout << result;
	}
}