#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> P;

struct customer
{
	customer(int number, int destRow, int destCol)
	{
		num = number;
		destR = destRow;
		destC = destCol;
	}
	int num, destR, destC;
};

struct pickup
{
	pickup(int r, int c, int n, int d)
	{
		row = r;
		col = c;
		num = n;
		dist = d;
	}
	int row, col; // 승객 위치
	int num; // 승객 번호
	int dist; // 승객까지 가는 거리
};

int dRow[4] = { 0, -1, 0, 1 };
int dCol[4] = { 1, 0, -1, 0 };

int N, M;
int currentFuel;

int grid[20][20];
int currRow, currCol;
P customerDest[401];

bool compare(pickup& a, pickup& b)
{
	if (a.dist == b.dist)
	{
		if (a.row == b.row)
		{
			return a.col < b.col;
		}
		else
		{
			return a.row < b.row;
		}
	}
	else
	{
		return a.dist < b.dist;
	}
}

pickup FindCustomer(int sRow, int sCol)
{
	bool visited[20][20];
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			visited[i][j] = false;

	vector<pickup> foundCustomers;

	queue<P> Q;
	visited[sRow][sCol] = true;
	Q.push(P(sRow, sCol));
	
	int level = 0;
	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			P curr = Q.front(); Q.pop();

			int r = curr.first;
			int c = curr.second;

			//printf("(%d, %d)\n", r, c);

			if (grid[r][c] < 0)
			{
				foundCustomers.push_back(pickup(r, c, -grid[r][c], level));
			}

			for (int i = 0; i < 4; i++)
			{
				int nRow = r + dRow[i];
				int nCol = c + dCol[i];

				if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
					continue;
				if (visited[nRow][nCol] || grid[nRow][nCol] == 1)
					continue;

				Q.push(P(nRow, nCol));
				visited[nRow][nCol] = true;
			}
		}
		level++;
	}

	sort(foundCustomers.begin(), foundCustomers.end(), compare);
	if (foundCustomers.empty())
	{
		return pickup(-1, -1, -1, -1);
	}
	else
	{
		return foundCustomers[0];
	}
}

int Move(int sRow, int sCol, int customerNo)
{
	bool visited[20][20];
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			visited[i][j] = false;

	vector<pickup> foundCustomers;

	queue<P> Q;
	visited[sRow][sCol] = true;
	Q.push(P(sRow, sCol));

	int level = 0;
	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			P curr = Q.front(); Q.pop();

			int r = curr.first;
			int c = curr.second;

			if (P(r, c) == customerDest[customerNo])
			{
				return level;
			}

			for (int i = 0; i < 4; i++)
			{
				int nRow = r + dRow[i];
				int nCol = c + dCol[i];

				if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
					continue;
				if (visited[nRow][nCol] || grid[nRow][nCol] == 1)
					continue;

				Q.push(P(nRow, nCol));
				visited[nRow][nCol] = true;
			}
		}
		level++;
	}

	return -1;

}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> currentFuel;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> grid[i][j];
		}
	}

	cin >> currRow >> currCol;
	currRow--;
	currCol--;

	for (int i = 1; i <= M; i++)
	{
		int sRow, sCol, eRow, eCol;
		cin >> sRow >> sCol >> eRow >> eCol;
		sRow--; sCol--; eRow--; eCol--;

		grid[sRow][sCol] = -i;
		customerDest[i] = P(eRow, eCol);
	}


	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << grid[i][j] << " ";
	//	}
	//	cout << endl;
	//}


	for(int i=0;i<M;i++)
	{
		pickup ret = FindCustomer(currRow, currCol);
		//printf("찾은 승객 : %d\n", ret.num);
		grid[ret.row][ret.col] = 0;

		if (ret.row == -1 && ret.col == -1)
		{
			//cout << "승객 찾기 실패 " << endl;
			cout << -1; return 0;
		}
		currentFuel -= ret.dist;
		//cout << "현재 연료 : " << currentFuel << endl;

		int moveDist = Move(ret.row, ret.col, ret.num);

		if (moveDist == -1)
		{
			//cout << "이동 실패 " << endl;
			cout << -1; return 0;
		}
		else
		{
			//cout << "이동 성공" << endl;
			currentFuel -= moveDist;
			//cout << "현재 연료 : " << currentFuel << endl;
			if (currentFuel < 0)
			{
				//cout << "연료 부족" << endl;
				cout << -1; return 0;
			}

			currentFuel += moveDist * 2;
			//cout << "연료 충전 후 : " << currentFuel << endl;
		}

		currRow = customerDest[ret.num].first;
		currCol = customerDest[ret.num].second;
	}

	cout << currentFuel;
}
