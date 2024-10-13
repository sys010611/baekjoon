#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int gears[4][8];

void RotateGear(int gearNo, int dir)
{
	//cout << "gear " << gearNo << " : " << dir << "방향 회전 " << endl;
	//cout << "전 : ";
	//for (int i = 0; i < 8; i++) cout << gears[gearNo][i] << " ";
	//cout << endl;

	if (dir == 1)
	{
		int last = gears[gearNo][7];

		for (int i = 7; i >= 1; i--)
		{
			gears[gearNo][i] = gears[gearNo][i-1];
		}
		gears[gearNo][0] = last;
	}
	else if (dir == -1)
	{
		int first = gears[gearNo][0];

		for (int i = 0; i <= 6; i++)
		{
			gears[gearNo][i] = gears[gearNo][i+1];
		}
		gears[gearNo][7] = first;
	}

	//cout << "후 : ";
	//for (int i = 0; i < 8; i++) cout << gears[gearNo][i] << " ";
	//cout << endl;
}

void Rotate(int gearNo, int rootGearDir)
{
	bool shouldRotate[4];
	int rotDir[4];

	fill(shouldRotate, shouldRotate + 4, false);

	shouldRotate[gearNo] = true;
	rotDir[gearNo] = rootGearDir;

	for (int curr = gearNo; curr <= 2; curr++)
	{
		if (gears[curr][2] != gears[curr + 1][6])
		{
			shouldRotate[curr + 1] = true;
			rotDir[curr + 1] = -rotDir[curr];
		}
		else
			break;
	}
	for (int curr = gearNo; curr >= 1; curr--)
	{
		if (gears[curr][6] != gears[curr - 1][2])
		{
			shouldRotate[curr - 1] = true;
			rotDir[curr - 1] = -rotDir[curr];
		}
		else
			break;
	}

	for (int i = 0; i < 4; i++)
	{
		if (shouldRotate[i])
		{
			RotateGear(i, rotDir[i]);
		}
	}
}

int GetResult()
{
	int score = 0;
	gears[0][0] == 0 ? score += 0 : score += 1;
	gears[1][0] == 0 ? score += 0 : score += 2;
	gears[2][0] == 0 ? score += 0 : score += 4;
	gears[3][0] == 0 ? score += 0 : score += 8;
	return score;
}

void Print()
{
	for (int i = 0; i < 4; i++)
	{
		cout << "gear " << i << " : ";
		for (int j = 0; j < 8; j++)
		{
			cout << gears[i][j] << " ";
		}
	}
	cout << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 4; i++)
	{
		string str; cin >> str;
		for (int j = 0; j < str.length(); j++)
			gears[i][j] = str[j] - '0';
	}
	//Print();

	int K; cin >> K;
	while (K--)
	{
		//cout << "회전 수행" << endl;
		int gearNo, dir;
		cin >> gearNo >> dir;

		Rotate(gearNo-1, dir);

		//Print();
	}

	cout << GetResult();
}