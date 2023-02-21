#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int matrix[2188][2188];
map<int,int> result;

void solve(int row, int col, int size)
{
	bool sameFlag = true;
	int start = matrix[row][col];
	//cout << "시작점: " << row << ", " << col << endl;
	//cout << "현재 사이즈: " << size << endl;

	for (int i = row; i < row + size; i++)
	{
		for (int j = col; j < col + size; j++)
		{
			if (matrix[i][j] != start)
			{
				sameFlag = false;
			}
		}
	}

	if (sameFlag == true)
	{
		//cout << "영역 내 모든 숫자 동일" << endl;
		result[start]++;
	}
	else
	{
		//cout << "영역 내 숫자 불일치, 분할 실행" << endl;
		for (int i = row; i < row+size; i += size/3)
		{
			for (int j = col; j < col+size; j += size/3)
			{
				solve(i,j,size/3);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	result[-1] = 0;
	result[0] = 0;
	result[1] = 0;

	solve(1,1,n);

	cout << result[-1] << endl << result[0] << endl << result[1] << endl;
}