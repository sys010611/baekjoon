#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int map[10][10];
int result = -1;

bool CanCovered(int currMap[10][10], int row, int col, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (row + i < 0 || row + i >= 10 && col + j < 0 || col + j >= 10)
			{
				return false;
			}
			if (currMap[row + i][col + j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

void AttachPaper(int currMap[10][10], int row, int col, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			currMap[row + i][col + j] = 0;
		}
	}
}

void DetachPaper(int currMap[10][10], int row, int col, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			currMap[row + i][col + j] = 1;
		}
	}
}

void Backtrack(int remainingPapers[5], int currMap[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (currMap[i][j] == 1)
			{
				for (int size = 1; size <= 5; size++)
				{
					if (CanCovered(currMap, i, j, size))
					{
						if (remainingPapers[size - 1] > 0)
						{
							AttachPaper(currMap, i, j, size);
							remainingPapers[size - 1]--;
							Backtrack(remainingPapers, currMap);
							remainingPapers[size - 1]++;
							DetachPaper(currMap, i, j, size);
						}
					}
				}

				// 왜 여기서 리턴을 해도 되느냐?
				// 한번 마주친 구역은 무조건 해결을 하고 갈거고,
				// 사이즈별로 다 붙여봤다면 백트래킹도 다 해봤을 것이므로 굳이 뒷부분을 해볼 필요 없다.
				return;
			}

			if (i == 9 && j == 9)
			{
				// 색종이 몇개 썼는지 카운트, result 업데이트
				int count = 0;
				for (int i = 0; i < 5; i++)
				{
					count += (5 - remainingPapers[i]);
				}
				if (result == -1 || count < result)
				{
					result = count;
				}
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> map[i][j];
		}
	}

	int remainingPapers[5] = {5,5,5,5,5};

	Backtrack(remainingPapers, map);
	cout << result;
}
