#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <deque>
#include <queue>
using namespace std;

typedef pair<int, int> P;

void PrintBoard(int n, int  board[20][20])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char c;
	cin >> c;
	cout << (int)c;
}
