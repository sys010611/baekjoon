#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int result = 0;
vector<vector<bool>> board; //퀸이 배치되어있는 칸은 true
vector<bool> col_visited;

void InitBoard()
{
	board.resize(N);
	for (int i = 0; i < N; i++)
		board[i].resize(N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = false;

	col_visited.resize(N);
	fill(col_visited.begin(), col_visited.end(), false);
}

bool CheckIfAvailable(int row, int col)
{
	// 윗 방향 검사
	if (col_visited[col] == true)
		return false;
		
	// 윗 방향 대각선 검사
	for (int i = 1; i < N; i++)
	{
		if(row-i>=0 && col-i >= 0 && board[row-i][col-i] == true)
			return false;
		if(row - i >= 0 && col + i < N && board[row-i][col+i] == true)
			return false;
	}

	//여기까지 리턴 안되고 왔다면 배치 가능한 것.
	return true;
}

/// <summary>
/// 현재 열에 퀸을 배치 시도한다. (위 -> 아래 열 순으로 배치 시도)
/// </summary>
void SetQueen(int row)
{
	for (int col = 0; col < N; col++)
	{
		if (CheckIfAvailable(row, col)) //놓을 수 있다면
		{
			board[row][col] = true; //퀸을 배치
			col_visited[col] = true; //열 사용 완료 표시

			if (row == N-1) // 마지막 열까지 배치했다면
			{
				//PrintBoard();
				result += 1;

				//이전 상태로 복귀.
				board[row][col] = false;
				col_visited[col] = false;
				continue;
			}

			SetQueen(row+1);

			//이전 상태로 복귀.
			board[row][col] = false;
			col_visited[col] = false;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	InitBoard();

	SetQueen(0);

	cout << result;
}