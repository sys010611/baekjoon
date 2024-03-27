#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
using namespace std;

int R, C;

char charMap[1500][1500];
int map[1500][1500];
int p[2250000];

int dRow[] = {0,1,0,-1};
int dCol[] = {1,0,-1,0};

vector<pair<int,int>> swan;

queue<pair<int,int>> bfsQ;
queue<pair<int,int>> unionQ;

int Find(int n)
{
	if(p[n] == -1)
		return n;
	else
		return p[n] = Find(p[n]);
}

void Merge(int a, int b)
{
	int rootA = Find(a);
	int rootB = Find(b);

	p[rootB] = rootA;
}

void MergeAll()
{
	while (!unionQ.empty())
	{
		int currRow = unionQ.front().first;
		int currCol = unionQ.front().second;
		//cout << "현재 물 좌표: " << currRow << ", " << currCol << endl << endl;
		unionQ.pop();
		bfsQ.push(make_pair(currRow, currCol));

		for (int i = 0; i < 4; i++)
		{
			int nextRow = currRow + dRow[i];
			int nextCol = currCol + dCol[i];

			if (nextRow < 0 || nextRow >= R || nextCol < 0 || nextCol >= C || map[nextRow][nextCol] == 0)
				continue;

			int waterA = map[currRow][currCol];
			int waterB = map[nextRow][nextCol];
			if (Find(waterA) != Find(waterB))
			{
				Merge(waterA, waterB);
			}
		}
	}
}

void BFS()
{
	while (!bfsQ.empty())
	{
		int currRow = bfsQ.front().first;
		int currCol = bfsQ.front().second;
		bfsQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextRow = currRow + dRow[i];
			int nextCol = currCol + dCol[i];

			if (nextRow < 0 || nextRow >= R || nextCol < 0 || nextCol >= C || map[nextRow][nextCol] != 0)
				continue;

			// 얼음 녹이기 (자기 집합으로 가져오기)
			map[nextRow][nextCol] = map[currRow][currCol];
			unionQ.push(make_pair(nextRow, nextCol));
		}
	}
}

void PrintMap()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	cin >> R >> C;

	memset(p, -1, sizeof(p));

	int waterCount = 1;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char input;
			cin >> input;
			charMap[i][j] = input;

			if (input == '.')
			{
				unionQ.push(make_pair(i,j));
				map[i][j] = waterCount++;
			}
			if (input == 'L')
			{
				swan.push_back(make_pair(i,j));

				unionQ.push(make_pair(i, j));
				map[i][j] = waterCount++;
			}
		}
	}

	//PrintMap();

	MergeAll();
	BFS();

	int level = 1;
	while (true)
	{
		MergeAll();

		//PrintMap();

		// 이 두개가 같은 컴포넌트에 속해있어야 성공
		int water1 = map[swan[0].first][swan[0].second];
		int water2 = map[swan[1].first][swan[1].second];

		//cout << "백조 1 집합: " << Find(water1) << endl;
		//cout << "백조 2 집합: " << Find(water2) << endl << endl;

		if (Find(water1) == Find(water2))
		{
			cout << level;
			return 0;
		}

		BFS();

		level++;
	}
}