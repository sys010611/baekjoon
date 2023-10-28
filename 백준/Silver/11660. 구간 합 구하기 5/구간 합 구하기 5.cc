#include <iostream>
using namespace std;

unsigned int map[1024][1024];
int N, M;

void Preprocessing()
{
	for (int i = 1; i < N; i++)
	{
		map[0][i] = map[0][i] + map[0][i-1];
		map[i][0] = map[i][0] + map[i-1][0];
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			map[i][j] = map[i][j-1] + map[i-1][j] - map[i-1][j-1] + map[i][j];
		}
	}
}

int getSum(int x1, int y1, int x2, int y2)
{
	//cout << map[x2][y2] << " " << map[x2][y1 - 1] << " " << map[x1 - 1][y2] <<" " << map[x1 - 1][y1 - 1]<<endl;

	//예외처리
	if(x1 == 0 && y1 == 0)
		return map[x2][y2];
	else if (x1 == 0)
		return map[x2][y2] - map[x2][y1 - 1];
	else if (y1 == 0)
		return map[x2][y2] - map[x1 - 1][y2];


	return map[x2][y2] - map[x2][y1-1] - map[x1-1][y2] + map[x1-1][y1-1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	Preprocessing();

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << map[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	for (int i = 0; i < M; i++)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << getSum(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << "\n";
	}
}
