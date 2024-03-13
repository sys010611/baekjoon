#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

typedef pair<int, int> P;

int R, C;
char map[20][20];

int dRow[4] = { 0,1,0,-1 };
int dCol[4] = {1,0,-1,0};

int dfsMaxDepth = -1;

/// 인덱스: 알파벳 - 65 (해당 알파벳을 지나왔는지)
bool visited[26];

void PrintMap()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}

bool IsVisitable(int targetRow, int targetCol)
{
	if(targetRow < 0 || targetRow >= R) return false;
	if(targetCol < 0 || targetCol >= C) return false;

	if (!visited[map[targetRow][targetCol] - 65]) // not visited alphabet
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DFS(int currRow, int currCol, int depth)
{
	if(dfsMaxDepth < depth)
		dfsMaxDepth = depth;

	//cout << "현재 char : " << map[currRow][currCol] << endl;
	//cout << "현재 depth : " << depth << endl;

	visited[map[currRow][currCol]-65] = true;

	for (int i = 0; i < 4; i++)
	{
		int targetRow = currRow + dRow[i];
		int targetCol = currCol + dCol[i];
		if (IsVisitable(targetRow, targetCol))
		{
			DFS(targetRow, targetCol, depth+1);
		}
	}

	//돌아갈 때는 플래그 다시 false로
	visited[map[currRow][currCol] - 65] = false;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(visited, visited + 26, false);

	cin >> R >> C;

	string input;
	for (int i = 0; i < R; i++)
	{
		cin >> input;
		for (int j = 0; j < C; j++)
		{
			map[i][j] = input[j];
		}
	}

	//PrintMap();

	unordered_set<char> usedCharList;

	DFS(0,0,1);

	printf("%d",dfsMaxDepth);
}