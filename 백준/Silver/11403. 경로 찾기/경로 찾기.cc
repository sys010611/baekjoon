#include <iostream>
#include <algorithm>
using namespace std;

int movable[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			movable[i][j] = 0;
		}
	}

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> movable[i][j];
		}
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!movable[i][j])
				{
					if (movable[i][k] && movable[k][j])
					{
						movable[i][j] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << movable[i][j] << " ";
		}
		cout << endl;
	}
}