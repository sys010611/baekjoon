#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <bitset>
using namespace std;

int result = 0;

int n,m,k;
vector<vector<pair<int, int>>> adjList; // <인접 섬 번호, capacity>
int jewelNo[100]; // idx번 섬이 가지고있는 보석의 번호.
bool visited[100][1<<14]; //보석의 소지 상태에 따라 방문 여부도 나눔

int bitCount(int A)
{
	if(A == 0) 
		return 0;

	return A%2 + bitCount(A/2);
}

void backtrack(int curr, int jewelStatus)
{
	visited[curr][jewelStatus] = true;

	if (curr == 0) // 0번 섬으로 돌아왔을 경우
	{
		//cout << "0번 섬으로 복귀, jewelStatus: " << bitset<6>(jewelStatus) << endl;
		int currResult = 0;
		if (jewelNo[curr] != -1)
		{
			currResult = bitCount(jewelStatus | 1<<jewelNo[curr]);
		}
		else
		{
			currResult = bitCount(jewelStatus);
		}
			
		if(currResult > result)
			result = currResult;
	}

	if (jewelNo[curr] != -1 && curr != 0) //만약 현재 섬에 보석이 있다면
	{
		//cout << curr <<" 번 섬에는 보석이 있음" << endl;
		for (auto next : adjList[curr]) // 보석을 줍고 가보기
		{
			int nextNum = next.first;
			int capacity = next.second;

			if (visited[nextNum][jewelStatus | 1 << jewelNo[curr]])
				continue;

			if (bitCount(jewelStatus | 1 << jewelNo[curr]) <= capacity)
			{
				backtrack(nextNum, jewelStatus | 1 << jewelNo[curr]);
			}
		}
	}

	for (auto next : adjList[curr]) // 보석을 안 줍고 가보기
	{
		int nextNum = next.first;
		int capacity = next.second;

		if (visited[nextNum][jewelStatus])
			continue;

		if (bitCount(jewelStatus) <= capacity)
		{
			backtrack(nextNum, jewelStatus);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();

	memset(jewelNo, -1, sizeof(jewelNo));

	cin >> n >> m >> k;

	adjList.resize(n);

	for (int i = 0; i < k; i++)
	{
		int input;
		cin >> input;
		jewelNo[input-1] = i;
	}

	int a,b,c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		adjList[a-1].push_back(make_pair(b-1, c));
		adjList[b-1].push_back(make_pair(a-1, c));
	}

	backtrack(0, 0);

	cout << result;
}
