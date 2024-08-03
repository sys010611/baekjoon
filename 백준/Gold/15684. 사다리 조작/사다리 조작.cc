#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M, H;

int parallelLines[10][30]; //[세로줄][가로줄]

bool Check()
{
	for (int i = 0; i < N; i++) // i: 시작 세로줄 번호
	{
		//cout << i << "에서 시작" << endl;
		int verticalLine = i;
		
		for (int j = 0; j < H; j++)
		{
			if (parallelLines[verticalLine][j] != -1) // 가로줄이 존재한다면 줄 변경
			{
				//cout << j << "레벨 에서 " << parallelLines[verticalLine][j] << "으로 줄 변경" << endl;

				verticalLine = parallelLines[verticalLine][j];
			}
		}
		//cout << verticalLine << "에서 끝" << endl;
		if(verticalLine != i)
			return false;
	}
	return true;
}


bool SetLineAndCheck(int maxCount, int vertical, int parallel, int currCount)
{
	if (parallelLines[vertical][parallel] != -1 || parallelLines[vertical+1][parallel] != -1) // 설치 불가
		return false;

	// 설치
	parallelLines[vertical][parallel] = vertical + 1;
	parallelLines[vertical + 1][parallel] = vertical;

	//cout << vertical << " <-> " << vertical+1 << "로 " << parallel << "에 설치 완료" << endl;
	currCount++;

	if (currCount == maxCount) // 목표 개수만큼 설치했다면 체크
	{
		//cout << currCount << "개 만큼 설치 완료, 체크" << endl;

		if (Check())
		{
			//cout << "성공" << endl;
			return true;
		}

		// 원상복구
		parallelLines[vertical][parallel] = -1;
		parallelLines[vertical + 1][parallel] = -1;
		return false;
	}

	// 이어서 추가 설치
	for (int j = parallel + 1; j < H; j++)
	{
		if (SetLineAndCheck(maxCount, vertical, j, currCount))
		{
			return true;
		}
	}
	for (int i = vertical + 1; i < N - 1; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (SetLineAndCheck(maxCount, i, j, currCount))
			{
				return true;
			}
		}
	}


	// 추가 설치를 다 해보고도 안되었던 경우
	// 원상복구
	parallelLines[vertical][parallel] = -1;
	parallelLines[vertical + 1][parallel] = -1;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> H;

	memset(parallelLines, -1, sizeof(parallelLines));

	for (int i = 0; i < M; i++)
	{
		int a,b;
		cin >> a >> b;
		a--; b--;

		parallelLines[b][a] = b+1;
		parallelLines[b+1][a] = b;
	}

	if (Check())
	{
		cout << 0;
		return 0;
	}
	else
	{
		// 가로선 1개 추가해서 재시도
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < H; j++)
			{
				if (SetLineAndCheck(1, i, j, 0))
				{
					cout << 1;
					return 0;
				}
			}
		}

		// 가로선 2개 추가해서 재시도
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < H; j++)
			{
				if (SetLineAndCheck(2, i, j, 0))
				{
					cout << 2;
					return 0;
				}
			}
		}

		// 가로선 3개 추가해서 재시도
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < H; j++)
			{
				if (SetLineAndCheck(3, i, j, 0))
				{
					cout << 3;
					return 0;
				}
			}
		}
	}

	cout << -1;
	return 0;
}