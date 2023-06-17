#include <iostream>
#include <algorithm>
using namespace std;

int map[500][500];
int n, m, b;
int popCount, pushCount;

int flatten(int freqNum)
{
	popCount = pushCount = 0;
	int currB = b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] > freqNum)
			{
				popCount = popCount + (map[i][j] - freqNum);
				currB = currB + (map[i][j] - freqNum);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] < freqNum)
			{
				pushCount = pushCount + (freqNum - map[i][j]);
				currB = currB - (freqNum - map[i][j]);
				if(currB <0)
					return -1;
			}
		}
	}
	int time = popCount * 2 + pushCount;
	return time;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> b;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	int avgHeight = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			avgHeight += map[i][j];
	avgHeight /= (n*m); 

	int time = 100000000;
	int resultHeight = avgHeight;
	while (true)
	{
		int resultTime = flatten(avgHeight);
		if(resultTime == -1 || time < resultTime)
			break;
		else if (time >= resultTime)
		{
			time = resultTime;
			resultHeight = avgHeight;
			avgHeight++;
		}
	}
	
	cout << time << " " << resultHeight;
	return 0;
}