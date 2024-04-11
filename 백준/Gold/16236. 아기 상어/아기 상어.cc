#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <deque>
#include <queue>
using namespace std;

typedef pair<int,int> P;

int dRow[] = {0, -1, 0, 1};
int dCol[] = {1, 0, -1, 0};

int N;
int board[20][20];
int level = 2;
int killCount = 0;
int currTime = 0;

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

/// <summary>
/// 이동 후 상어의 위치를 리턴
/// </summary>
P BFS(int startRow, int startCol)
{
	bool visited[20][20];
	memset(visited, 0, sizeof(visited));

	vector<P> fishList;

	queue<P> Q;
	Q.push(P(startRow, startCol));
	visited[startRow][startCol] = true;

	int phase = 0;

	bool found = false;

	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			int currRow = Q.front().first;
			int currCol = Q.front().second;
			Q.pop();

			//cout << "currRow : " << currRow << endl;
			//cout << "currCol : " << currCol << endl;

			for (int i = 0; i < 4; i++)
			{
				int nRow = currRow + dRow[i];
				int nCol = currCol + dCol[i];

				//cout << "nRow: " << nRow << endl;
				//cout << "nCol: " << nCol << endl;

				//범위 밖인 경우, 자신보다 큰 물고기를 만났을 경우
				if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N || board[nRow][nCol] > level)
				{
					//cout << "범위 밖 / 큰 물고기 " << endl;
					continue;
				}

				// 잡아먹을 수 있는 물고기를 만났을 경우
				if (board[nRow][nCol] != 0 && board[nRow][nCol] < level)
				{
					//cout << "먹을 수 있는 물고기 발견" << endl;
					found = true;
					fishList.push_back(P(nRow, nCol));

					if (!visited[nRow][nCol])
					{
						visited[nRow][nCol] = true;
						Q.push(P(nRow, nCol));
					}
					continue;
				}

				// 이 외 (그냥 지나갈 수 있을 경우)
				//cout << "진행 가능 " << endl;
				if (!visited[nRow][nCol])
				{
					visited[nRow][nCol] = true;
					Q.push(P(nRow, nCol));
				}
			}
		}
		phase++;

		if(found)
			break;
	}

	if (found) // 잡아먹을 물고기를 찾은 경우
	{
		sort(fishList.begin(), fishList.end());
		// 물고기 잡아먹음. 레벨, 킬 카운트 처리
		P fishPos = *fishList.begin();

		board[fishPos.first][fishPos.second] = 0;
		//cout <<"board 업데이트 완료" << endl;
		//cout << fishPos.first << " " << fishPos.second << endl;

		killCount++;
		if (killCount == level)
		{
			level++;
			killCount = 0;
		}
		// 잡아먹은 좌표 리턴
		currTime += phase;
		return *fishList.begin();
	}
	else // 잡아먹을 물고기가 없어서, 즉 큐가 그대로 비어서 나온 경우
	{
		//cout << "잡아먹을게 없음" << endl;
		return P(-1,-1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int currRow, currCol;

	cin >> N;
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				currRow = i;
				currCol = j;

				board[i][j] = 0;
			}
		}

	int count = 0;
	while (currRow != -1 && currCol != -1)
	{
		//PrintBoard();

		P result = BFS(currRow, currCol);
		currRow = result.first;
		currCol = result.second;

		/*count ++;
		if(count == 3)
			break;*/
	}

	cout << currTime;
}