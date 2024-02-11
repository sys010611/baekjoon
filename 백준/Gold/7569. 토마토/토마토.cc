#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<vector<int>>> box; // [행][열][높이]

//열 / 행 / 높이
int M, N, H;

struct loc
{
	loc(int row, int col, int height)
	{
		this->row = row;
		this->col = col;
		this->height = height;
	}

	int row;
	int col; 
	int height;
};

int dRow[]{1,0,-1,0,0,0};
int dCol[]{0,1,0,-1,0,0};
int dHei[]{0,0,0,0,-1,1};

bool IsInRange(int row, int col, int height)
{
	if (row < 0 || row >= N)
		return false;

	if (col < 0 || col >= M)
		return false;

	if (height < 0 || height >= H)
		return false;

	if (box[row][col][height] == -1)
		return false;

	if (box[row][col][height] == 1)
		return false;
	

	return true;
}

int BFS()
{
	//cout << "BFS START" << endl;

	queue<loc> Q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < H; k++)
			{
				if (box[i][j][k] == 1)
				{
					Q.push(loc(i,j,k));
				}
			}
		}
	}

	int level = 0;
	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			loc currLoc = Q.front(); Q.pop();
			int r = currLoc.row;
			int c = currLoc.col;
			int h = currLoc.height;

			//printf("currLoc: %d %d %d", r, c, h);

			for (int i = 0; i < 6; i++)
			{
				if (IsInRange(r + dRow[i], c + dCol[i], h + dHei[i]))
				{
					Q.push(loc(r + dRow[i], c + dCol[i], h + dHei[i]));

					box[r + dRow[i]][c + dCol[i]][h + dHei[i]] = 1;
				}
			}

		}
		level++;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < H; k++)
			{
				if (box[i][j][k] == 0) // 안 익은 토마토가 존재
				{
					return -1;
				}
			}
		}
	}

	return level - 1;
}

int main()
{
	cin >> M >> N >> H;


	box.resize(N);
	//visited.resize(N);

	for (int i = 0; i < N; i++)
	{
		box[i].resize(M);
		//visited[i].resize(M);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			box[i][j].resize(H);
			//visited[i][j].resize(H);
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> box[j][k][i];
			}
		}
	}

	//cout << "1층: " << endl;
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		cout << box[i][j][0] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << "2층: " << endl;
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		cout << box[i][j][1] << " ";
	//	}
	//	cout << endl;
	//}

	cout << BFS();
}