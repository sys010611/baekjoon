#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

int R, C;
bool visited[10000][500];

int result = 0;

void Proceed(int row, int col, bool& success)
{
	//cout << "현재 위치 : " << row << " , " << col << endl;
	visited[row][col] = true;

	if (col == C-1)
	{
		result++;

		success = true;
		return;
	}

	// 먼저 위로 시도
	if(row-1 >= 0 && !visited[row-1][col+1])
		Proceed(row - 1, col + 1, success);

	// 위로 가서 성공하지 못한 경우
	if(!success && !visited[row][col+1])
		Proceed(row, col + 1, success);

	// 중간으로 가서 성공하지 못한 경우
	if(!success && row+1 < R && !visited[row+1][col+1])
		Proceed(row + 1, col + 1, success);

	//// 끝까지 성공하지 못했다면, 왔던 길의 visited 원상복구
	//if(!success)
	//{
	//	visited[row][col] = false;
	//	return;
	//}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(&visited[0][0], &visited[9999][500], false);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < C; j++)
		{
			if(input[j] == 'x')
				visited[i][j] = true;
		}
	}
	for (int row = 0; row < R; row++)
	{
		//cout << row << ", 0 부터 시작" << endl;
		bool success = false;
		Proceed(row, 0, success);
	}

	//for (int i = 0; i < R; i++)
	//{
	//	for (int j = 0; j < C; j++)
	//	{
	//		cout << visited[i][j];
	//	}
	//	cout << endl;
	//}
	cout << result;
}