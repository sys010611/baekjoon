#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[50][50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> chickenHouse; //치킨집의 행, 열 저장
	vector<pair<int,int>> house; //집의 행, 열 저장
	vector<int> temp; //조합 뽑아내기 용 벡터
	int CHCount = 0;
	int result = 100000000;

	int input;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			map[i][j] = input;

			if (input == 1)
			{
				house.push_back({i,j});
			}
			else if (input == 2)
			{
				chickenHouse.push_back({ i,j });
				CHCount++;
			}
		}

	for (int i = 0; i < CHCount; i++)
	{
		if(i < M)
			temp.push_back(0);
		else
			temp.push_back(1);
	}

	/*for (vector<pair<int, int>>::iterator it = chickenHouse.begin(); it != chickenHouse.end(); it++)
	{
		cout << (*it).first << " " << (*it).second << endl;
	}*/

	do
	{
		vector<pair<int,int>> currChickenHouses; //M개 뽑아낸 치킨집의 행, 열 저장
		for (int i = 0; i < CHCount; i++)
		{
			if (temp[i] == 0)
			{
				currChickenHouses.push_back(chickenHouse[i]);
			}
		}

		//치킨거리 계산
		int totalDist = 0; //여기에 누적
		for (auto& oneHouse : house) //각 집마다
		{
			int myDist = 100000000; //집에서 가장 가까운 치킨집까지의 거리 저장
			for (auto& oneChickenHouse : currChickenHouses) //조합으로 뽑아낸 모든 치킨집에 대해 거리 계산
			{
				int currDist = abs(oneHouse.first - oneChickenHouse.first) + abs(oneHouse.second - oneChickenHouse.second);
				if(currDist < myDist)
					myDist = currDist;

			}
			totalDist += myDist;
			//cout << "한 집에서의 myDist: " << myDist << endl;
		}
		if (totalDist < result)
		{
			result = totalDist;
			//cout << "result 갱신 : " << result << endl;
		}
	}
	while(next_permutation(temp.begin(), temp.end()));

	cout << result;
}