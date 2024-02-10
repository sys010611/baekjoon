#include <iostream>
#include <vector>
using namespace std;

int N,M;
int board[500][500];

vector<vector<pair<int,int>>> blockList;

void PrintBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

/// <summary>
/// 블록 하나를 보드에 놓고, 그 때의 점수를 리턴한다.
/// 블록이 보드를 벗어날 시 0점을 준다.
/// </summary>
int SetBlockOnBoard(int baseRow, int baseCol, const vector<pair<int,int>> block)
{
	int score = 0;

	for (int i = 0; i < 4; i++)
	{
		int row = baseRow + block[i].first;
		int col = baseCol + block[i].second;

		if(row < 0 || row >= N)
			return 0;

		if(col < 0 || col >= M)
			return 0;

		score += board[row][col];
	}
	return score;
}

int main()
{
	// 기본 도형
	blockList.push_back({ {0,0}, {0,1}, {0,2}, {0,3} });
	blockList.push_back({ {0,0}, {0,1}, {1,0}, {1,1} });
	blockList.push_back({ {0,0}, {1,0}, {2,0}, {2,1} });
	blockList.push_back({ {0,0}, {1,0}, {1,1}, {2,1} });
	blockList.push_back({ {0,0}, {0,1}, {0,2}, {1,1} });

	// 회전 / 대칭
	blockList.push_back({ {0,0}, {1,0}, {2,0}, {3,0} });

	blockList.push_back({ {0,0}, {0,1}, {0,2}, {1,0} });
	blockList.push_back({ {0,0}, {0,1}, {1,1}, {2,1} });
	blockList.push_back({ {0,2}, {1,0}, {1,1}, {1,2} });
	blockList.push_back({ {0,1}, {1,1}, {2,0}, {2,1} });
	blockList.push_back({ {0,0}, {1,0}, {1,1}, {1,2} });
	blockList.push_back({ {0,0}, {0,1}, {1,0}, {2,0} });
	blockList.push_back({ {0,0}, {0,1}, {0,2}, {1,2} });

	blockList.push_back({ {0,1}, {0,2}, {1,0}, {1,1} });
	blockList.push_back({ {0,1}, {1,0}, {1,1}, {2,0} });
	blockList.push_back({ {0,0}, {0,1}, {1,1}, {1,2} });

	blockList.push_back({ {0,1}, {1,0}, {1,1}, {2,1} });
	blockList.push_back({ {0,1}, {1,0}, {1,1}, {1,2} });
	blockList.push_back({ {0,0}, {1,0}, {2,0}, {1,1} });

	//for (auto it1 = blockList.begin(); it1 != blockList.end(); it1++)
	//{
	//	for (vector<pair<int,int>>::iterator it2 = it1->begin(); it2 != it1->end(); it2++)
	//	{
	//		cout << it2->first << " " << it2->second << " , ";
	//	}
	//	cout << endl;
	//}
	//return 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	//PrintBoard();



	int max = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (auto it = blockList.begin(); it != blockList.end(); it++)
			{
				int result = SetBlockOnBoard(i, j, *it);
				
				if(result > max)
					max = result;
			}
		}
	}

	cout << max;
}