#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#include <cstring>
#include <bitset>
#include <set>
using namespace std;

#define SIZE 101
int dRow[] = { 0, -1, 0, 1 };
int dCol[] = { 1, 0, -1, 0 };
char map[SIZE][SIZE];
bool visited[SIZE][SIZE];
int w, h;

set<pair<int, int>> acquiredDocPos;
int ret;

void DFS(int currRow, int currCol, int currKeys)
{
	if (visited[currRow][currCol])
		return;

	visited[currRow][currCol] = true;

	//printf("%d, %d 방문\n", currRow, currCol);
	//cout << "열쇠 현황 : " << bitset<26>(currKeys) << endl;

	char curr = map[currRow][currCol];

	if ('a' <= curr && curr <= 'z')
	{
		// 이미 가지고 있던 열쇠라면
		if (currKeys & (1 << (curr - 'a')))
		{
			 // 그냥 진행
		}
		else
		{
			currKeys = currKeys | (1 << (curr - 'a'));
			//cout << "열쇠 습득 : " << curr << endl;
			memset(visited, 0, sizeof(visited)); // 방문배열 초기화
		}
	}

	if (curr == '$')
	{
		if (acquiredDocPos.find(pair<int, int>(currRow, currCol)) == acquiredDocPos.end())
		{
			ret++;
			acquiredDocPos.insert(pair<int, int>(currRow, currCol));
		}
	}

	for (int i = 0; i < 4; i++)
	{
		int nRow = currRow + dRow[i];
		int nCol = currCol + dCol[i];

		if (nRow < 0 || nCol < 0 || nRow > h + 1 || nCol > w + 1)
			continue;

		char next = map[nRow][nCol];

		if (visited[nRow][nCol] || next == '*')
		{
			continue;
		}
		else if ('A' <= next && next <= 'Z')
		{
			if (currKeys & (1 << (next - 'A')))
			{
				//cout << "열쇠 사용: " << next << endl;
				DFS(nRow, nCol, currKeys);
			}
			else
			{
				continue;
			}
		}
		else
		{
			DFS(nRow, nCol, currKeys);
		}
	}
}

signed main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ret = 0;
		acquiredDocPos = set<pair<int,int>>();

		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
			{
				map[i][j] = '.';
				visited[i][j] = false;
			}
				

		cin >> h >> w;
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				cin >> map[i][j];
			}
		}
		// padding
		for (int i = 0; i <= h + 1; i++)
		{
			map[i][0] = '.';
			map[i][w + 1] = '.';
		}
		for (int i = 0; i <= w + 1; i++)
		{
			map[0][i] = '.';
			map[h+1][i] = '.';
		}

		//for (int i = 0; i <= h + 1; i++)
		//{
		//	for (int j = 0; j <= w + 1; j++)
		//	{
		//		cout << map[i][j];
		//	}
		//	cout << endl;
		//}

		int currKeys = 0;

		string keys;
		cin >> keys;
		if (keys != "0")
		{
			for (char c : keys)
				currKeys = currKeys | (1 << (c - 'a'));
		}

		DFS(0,0,currKeys);

		cout << ret << endl;
	}
}

