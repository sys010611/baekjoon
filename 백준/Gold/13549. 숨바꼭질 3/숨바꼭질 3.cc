#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

int n, k;

int visited[100001];
queue<int> Q;


void TeleportCheck(int n)
{
	while (n <= 100000 && n >= 0)
	{
		if (!visited[n])
		{
			visited[n] = true;
			Q.push(n);
			n *= 2;

		}
		else
		{
			return;
		}
	}
}

int BFS()
{
	int level = 0;
	TeleportCheck(n);

	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			int curr = Q.front(); Q.pop();

			if (curr == k)
				return level;

			int a = curr + 1;
			int b = curr - 1;

			TeleportCheck(a);
			TeleportCheck(b);
		}
		level++;
	}
	assert(0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(visited, 0, sizeof(visited));

	cin >> n >> k;

	cout << BFS();
}