#include <iostream>
#include <bitset>
#include <queue>
#include <tuple>
using namespace std;

int N, M;
char map[50][50];
bool visited[50][50][1<<6];

int dRow[] = {1,0,-1,0};
int dCol[] = {0,1,0,-1};

queue<tuple<int,int,int>> Q;

int BFS()
{	
	int level = 1;
	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			int cRow = get<0>(Q.front());
			int cCol = get<1>(Q.front());
			int keyStatus = get<2>(Q.front());

			Q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nRow = cRow + dRow[i];
				int nCol = cCol + dCol[i];

				if(nRow < 0 || nRow >= N || nCol < 0 || nCol >= M) // out of range
					continue;

				if (map[nRow][nCol] == '.' || map[nRow][nCol] == '0')
				{
					if (!visited[nRow][nCol][keyStatus])
					{
						Q.push(make_tuple(nRow, nCol, keyStatus));
						visited[nRow][nCol][keyStatus] = true;
					}
				}
				else if (map[nRow][nCol] == '#')
					continue;
				else if (map[nRow][nCol] >= 'a' && map[nRow][nCol] <= 'f')
				{
					if (!visited[nRow][nCol][keyStatus])
					{
						//cout << "열쇠 획득 : " << map[nRow][nCol] << endl;
						//cout << "현재 레벨 : " << level << endl;
						Q.push(make_tuple(nRow, nCol, keyStatus | (1 << (map[nRow][nCol] - 'a')))); // 키 추가 후 큐에 푸쉬

						visited[nRow][nCol][keyStatus] = true;
						visited[nRow][nCol][keyStatus | (1 << (map[nRow][nCol] - 'a'))] = true;

					}
				}
				else if (map[nRow][nCol] >= 'A' && map[nRow][nCol] <= 'F')
				{
					if (!visited[nRow][nCol][keyStatus])
					{
						if ((keyStatus & (1 << (map[nRow][nCol] - 'A'))) != 0) // 키를 소지 중이었다면
						{
							//cout << "열쇠 사용 : " << map[nRow][nCol] << endl;
							//cout << "현재 레벨 : " << level << endl;
							Q.push(make_tuple(nRow, nCol, keyStatus));

							visited[nRow][nCol][keyStatus] = true;
						}
					}
				}
				else if (map[nRow][nCol] == '1')
				{
					return level;
				}
			}
		}
		level++;
	}

	return -1; // error
}

int main()
{
	cin >> N >> M;

	int startRow, startCol;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '0')
			{
				startRow = i;
				startCol = j;
			}
		}
		
	Q.push(make_tuple(startRow, startCol, 0));
	cout << BFS();
}