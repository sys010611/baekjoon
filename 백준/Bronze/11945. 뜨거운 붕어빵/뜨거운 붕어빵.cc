#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

char map[10][10];
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = m - 1; j > -1; j--)
		{
			cout << map[i][j];
		}
		cout << endl;	
	}
}
