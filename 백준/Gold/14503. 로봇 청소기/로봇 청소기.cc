#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int room[50][50]; // 0: 청소 필요  1: 벽  2: 청소 완료

// 북, 동, 남, 서 순서
int dRow[4] = {-1,0,1,0};
int dCol[4] = {0,1,0,-1};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int currRow, currCol;
	int currDir; // 0:북 1:동 2:남 3:서

	cin >> currRow >> currCol >> currDir;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> room[i][j];
		}
	}

	int result = 0;
	while (true)
	{
		// 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소
		if (room[currRow][currCol] == 0)
		{
			room[currRow][currCol] = 2;
			result++;
		}

		// 주변 4칸 중 청소 필요한 곳 있는지 확인
		bool isCleaningNeeded = false;
		for (int i = 0; i < 4; i++)
		{
			int nextRow = currRow + dRow[i];
			int nextCol = currCol + dCol[i];

			if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M) // out of range
			{
				continue;
			}
			if (room[nextRow][nextCol] == 0)
			{
				isCleaningNeeded = true;
				break;
			}
		}

		if (isCleaningNeeded)
		{
			// 반시계방향 90도 회전
			currDir = (currDir - 1 + 4)%4;
			// 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
			
			int nextRow = currRow + dRow[currDir];
			int nextCol = currCol + dCol[currDir];

			if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M) // out of range
			{
				continue;
			}

			if (room[nextRow][nextCol] == 0)
			{
				currRow= nextRow;
				currCol = nextCol;
				continue;
			}
		}
		else
		{
			// 후진할 수 있다면 후진하고 1번으로
			int movingDir = (currDir + 2)%4;
			int nextRow = currRow + dRow[movingDir];
			int nextCol = currCol + dCol[movingDir];

			//후진 불가능한 경우
			if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M) // out of range
			{
				break;
			}
			if (room[nextRow][nextCol] == 1)
			{
				break;
			}

			// 한칸 후진하고 처음으로
			currRow = nextRow;
			currCol = nextCol;
			continue;
		}


	}

	cout << result;
}