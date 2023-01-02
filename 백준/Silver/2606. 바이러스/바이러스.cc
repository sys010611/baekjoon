#include <iostream>

using namespace std;

int main()
{
	int comCount;
	cin >> comCount; //컴퓨터의 수

	int pairCount;
	cin >> pairCount; //컴퓨터 쌍의 수

	bool* isInfected = new bool[comCount]; //각 컴퓨터의 감염 유무
	for (int i = 0; i < comCount; i++)
		isInfected[i] = false;
	isInfected[0] = true; //1번 컴퓨터는 감염됨

	int** comPair = new int*[pairCount]; //각 컴퓨터 쌍을 저장할 2차원 배열
	for (int i = 0; i < pairCount; i++)
	{
		comPair[i] = new int[2];
	}

	for (int i = 0; i < pairCount; i++) //각 컴퓨터 쌍 배열에 저장
	{
		int a, b;
		cin >> a;
		cin >> b;

		a--;
		b--; //인덱스 값에 맞게 조정

		comPair[i][0] = a;
		comPair[i][1] = b;
	}

	for (int j = 0; j < pairCount; j++)
	{
		for (int i = 0; i < pairCount; i++)
		{
			if (isInfected[comPair[i][0]] == true || isInfected[comPair[i][1]] == true)
			{
				isInfected[comPair[i][0]] = true;
				isInfected[comPair[i][1]] = true;
			}
		}
	}
	
	int infectedComCount = 0; //감염된 컴퓨터의 수
	for (int i = 0; i < comCount; i++)
	{
		if (isInfected[i] != false)
		{
			infectedComCount++;
		}
	}
	infectedComCount--; //1번 컴퓨터는 제외

	cout << infectedComCount;
}