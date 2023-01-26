#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

char building[1001][1001];
queue<pair<int,int>> sangeunQ;
queue<pair<int,int>> fireQ;
bool fireVisited[1001][1001];
bool sangeunVisited[1001][1001];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1}; //동서남북 이동

int bfs(int w, int h, int initialX, int initialY)
{
	int fireX, fireY, sangeunX, sangeunY, nextSangeunX, nextSangeunY;
	

	sangeunY = initialY;
	sangeunX = initialX;

	//불 -> 상근 순으로 bfs 진행
	sangeunQ.push({sangeunY, sangeunX});

	//불의 좌표들을 큐에 push
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (building[i][j] == '*')
			{
				fireQ.push({ i, j });
			}
		}
	}

	int level = 0;

	while (!sangeunQ.empty())
	{
		int qSize = fireQ.size();
		//하나씩 빼면서 확산시키기
		while (qSize--)
		{
			fireY = fireQ.front().first;
			fireX = fireQ.front().second;
			fireQ.pop();
			//cout << "level " << level << ", 현재 불의 위치 " << fireY << " " << fireX << endl;

			for (int i = 0; i < 4; i++)
			{
				if (building[fireY + dy[i]][fireX + dx[i]] == '.' || building[fireY + dy[i]][fireX + dx[i]] == '@')
				{
					if (!fireVisited[fireY + dy[i]][fireX + dx[i]])
					{
						fireQ.push({ fireY + dy[i] , fireX + dx[i] });
						fireVisited[fireY + dy[i]][fireX + dx[i]] = true;
					}
				}
			}
		}

		int qsize = sangeunQ.size();
		while (qsize--)
		{
			sangeunY = sangeunQ.front().first;
			sangeunX = sangeunQ.front().second;
			sangeunQ.pop();

			//현재 빌딩의 모서리일 경우 level+1리턴
			if (sangeunX == 0 || sangeunX == w - 1)
			{
				return level+1;
			}
			else if (sangeunY == 0 || sangeunY == h - 1)
			{
				return level+1;
			}

			for (int i = 0; i < 4; i++)
			{
				nextSangeunY = sangeunY + dy[i];
				nextSangeunX = sangeunX + dx[i];
				if (building[nextSangeunY][nextSangeunX] == '.' && !sangeunVisited[nextSangeunY][nextSangeunX] && !fireVisited[nextSangeunY][nextSangeunX]) //빈 공간이며, 방문한적 없고, 아직 불이 옮겨붙지 않았을 경우
				{
					sangeunQ.push({ nextSangeunY, nextSangeunX });
					sangeunVisited[nextSangeunY][nextSangeunX] = true;
				}
			}
		}
		level++;
	}	

	// 큐가 비었다 -> 더이상 갈 곳이 없음
	return -1;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int w,h; //x축, y축
		cin >> w >> h;

		string input;
		
		int initialX,initialY; //상근의 처음 위치

		for (int i = 0; i < h; i++)
		{
			cin >> input;
			for (int j = 0; j < w; j++)
			{
				building[i][j] = input[j]; //지도 입력
				if (input[j] == '@') //상근이의 처음 위치가 나왔을 경우 저장
				{
					initialY = i;
					initialX = j;
				}
				fireVisited[i][j] = false;
				sangeunVisited[i][j] = false; //방문여부 초기화
			}
		}

		fireQ = queue<pair<int, int>>();
		sangeunQ = queue<pair<int, int>>();

		int result = bfs(w, h, initialX, initialY);
		if (result == -1)
		{
			cout << "IMPOSSIBLE" << "\n";
		}
		else
		{
			cout << result << "\n";
		}
	}
}