#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int img[64][64];
int N;

void Check(int range, int startRow, int startCol)
{
	//cout << "range : " << range << endl;
	//cout << "startRow : " << startRow << endl;
	//cout << "startCol : " << startCol << endl;

	int initValue = img[startRow][startCol];
	bool canCompress = true;
	for (int i = startRow; i <  startRow + range; i++)
	{
		for (int j = startCol; j < startCol + range; j++)
		{
			if (img[i][j] != initValue)
			{
				canCompress = false;
				break;
			}
		}
	}

	if (canCompress)
	{
		//cout << "성공 " << endl;
		cout << initValue;
	}
	else
	{
		//cout << "실패 " << endl;
		cout << '(';
		Check(range / 2, startRow, startCol);
		Check(range / 2, startRow, startCol + range / 2);
		Check(range / 2, startRow + range / 2, startCol);
		Check(range / 2, startRow + range / 2, startCol + range / 2);
		cout << ')';
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			img[i][j] = str[j] - '0';
		}
	}

	Check(N, 0, 0);
}
