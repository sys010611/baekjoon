#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
using namespace std;

int N;
int scores[11];
vector<int> region;
vector<vector<int>> adjList;
int result = INT_MAX;
vector<bool> visited;
int aScore;
int bScore;

void DFS(int currNode)
{
	int currRegion = region[currNode];

	visited[currNode] = true;
	
	if (currRegion == 0)
		aScore += scores[currNode];
	else
		bScore += scores[currNode];

	for (auto next : adjList[currNode])
	{
		if (!visited[next] && region[next] == currRegion)
		{
			DFS(next);
		}
	}
}

void Test()
{
	//cout << "Regions: " << endl;
	//for (auto item : region)
	//	cout << item << " ";
	//cout << endl;

	aScore = 0;
	bScore = 0;
	fill(visited.begin(), visited.end(), false);

	for (int i = 0; i < N; i++)
	{
		if (visited[i])
			continue;

		//cout << "i : " << i << endl;
		// 구역 나누기 실패
		if (region[i] == 0 && aScore != 0)
		{
			//cout << "divide failed" << endl;
			return;
		}
		if (region[i] == 1 && bScore != 0)
		{
			//cout << "divide failed" << endl;
			return;
		}

		DFS(i);
	}

	if (aScore == 0 || bScore == 0)
		return;

	result = min(result, abs(aScore - bScore));
}

void Backtrack(int idx)
{
	if (idx >= N)
	{
		Test();
		return;
	}

	region[idx] = 1;
	Backtrack(idx + 1);
	region[idx] = 0;
	Backtrack(idx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	adjList.resize(N);
	visited.resize(N);
	region.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> scores[i];
	}

	for (int i = 0; i < N; i++)
	{
		int adjCount;
		cin >> adjCount;
		while (adjCount--)
		{
			int adjNode; cin >> adjNode;
			adjList[i].push_back(adjNode-1);
		}
	}

	Backtrack(0);

	if (result == INT_MAX)
		cout << -1;
	else
		cout << result;
}