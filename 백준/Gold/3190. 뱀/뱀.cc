#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;

typedef pair<int, int> P;

int N, K, L;
deque<pair<int, char>> controls;
int board[100][100];
deque<pair<int, int>> snake;

// 우, 상, 좌, 하
int dRow[] = { 0,-1,0,1 };
int dCol[] = { 1,0,-1,0 };

void PrintBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(board, 0, sizeof(board));
	snake.push_front(P(0, 0));

	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int y, x;
		cin >> y >> x;
		board[y - 1][x - 1] = 1; //사과가 놓인 칸은 1로
	}

	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		controls.push_back(pair<int, char>(x, c));
	}

	// 오른쪽 방향으로 시작
	int currDir = 0;
	board[0][0] = 2; //뱀이 놓인 칸은 2로

	for (int time = 0; ; time++)
	{
		//cout << "time : " << time << endl;
		//PrintBoard();

		if (!controls.empty() && controls.begin()->first == time) // 방향전환을 해야할 시
		{
			//cout << "방향 전환 수행" << endl;

			char dir = controls.begin()->second;
			controls.pop_front();

			if (dir == 'L')
			{
				currDir = (currDir + 1) % 4;
			}
			else if (dir == 'D')
			{
				currDir = (currDir + 3) % 4;
			}
			//cout << "currDir : " << currDir << endl;
		}

		// 뱀의 다음 진행 위치 확인
		int nRow = snake.begin()->first + dRow[currDir];
		int nCol = snake.begin()->second + dCol[currDir];

		/*cout << "currRow : " << snake.begin()->first << endl;
		cout << "currCol : " << snake.begin()->second << endl;
		cout << "nRow : " << nRow << endl;
		cout << "nCol : " << nCol << endl;*/

		// 벽에 박았거나, 자기 몸에 박은 경우 게임 종료
		if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
		{
			cout << time + 1;
			return 0;
		}
		if (board[nRow][nCol] == 2)
		{
			cout << time + 1;
			return 0;
		}

		//가는 칸에 사과가 있다면 머리부분만 추가
		if (board[nRow][nCol] == 1)
		{
			snake.push_front(P(nRow, nCol));
			board[nRow][nCol] = 2;
		}
		else if (board[nRow][nCol] == 0) // 가는 칸이 빈 칸이라면 머리 추가, 꼬리 삭제
		{
			snake.push_front(P(nRow,nCol));
			board[nRow][nCol] = 2;
			
			P tailPos = *(snake.end() - 1);
			board[tailPos.first][tailPos.second] = 0;
			snake.pop_back();
		}
	}
}