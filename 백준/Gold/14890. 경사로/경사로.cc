#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N, L;
int grid[100][100];

bool CheckLine(vector<int>& line)
{
	vector<bool> placed(N);
	fill(placed.begin(), placed.end(), false);

	for (int i = 0; i < N - 1; i++)
	{
		int curr = line[i];
		int next = line[i + 1];

		if (curr != next)
		{
			if (curr + 1 == next)
			{
				int startIdx = i - L + 1;

				if (startIdx < 0)
					return false;

				// 배치해보기
				for (int j = startIdx; j <= i; j++)
				{
					if (line[j] != curr)
						return false;

					if (placed[j])
						return false;

					placed[j] = true;
				}
			}
			else if (curr - 1 == next)
			{
				int endIdx = i + L;

				if (endIdx >= N)
					return false;

				// 배치해보기
				for (int j = i + 1; j <= endIdx; j++)
				{
					if (line[j] != next)
						return false;

					if (placed[j])
						return false;

					placed[j] = true;
				}

			}
			else
				return false;
		}
	}
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> grid[i][j];
		}
	}

	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		vector<int> rowLine, colLine;
		for (int j = 0; j < N; j++)
		{
			rowLine.push_back(grid[i][j]);
			colLine.push_back(grid[j][i]);
		}
		if (CheckLine(rowLine))
			ret++;
		if (CheckLine(colLine))
			ret++;
	}
	cout << ret;
}
