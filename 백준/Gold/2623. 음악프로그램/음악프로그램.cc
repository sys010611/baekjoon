#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
vector<int> indegree;
vector<vector<int>> adjList;

void PrintGraph()
{
	cout << "adjList: " << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << i << "->";
		for (auto it = adjList[i].begin(); it != adjList[i].end(); it++)
		{
			cout << *it << ", ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "indegree : " << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << i << ": " << indegree[i] << endl;
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	adjList.resize(N + 1);
	indegree.resize(N + 1);
	fill(indegree.begin(), indegree.end(), 0);

	int singerCount;
	for (int i = 0; i < M; i++)
	{
		cin >> singerCount;

		int prev, curr;
		cin >> prev;

		for (int i = 1; i < singerCount; i++)
		{
			cin >> curr;
			indegree[curr] += 1;
			adjList[prev].push_back(curr);
			prev = curr;
		}
	}

	//PrintGraph();

	vector<int> result;

	//위상 정렬
	queue<int> Q;
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			Q.push(i);
		}
	}

	for(int i=0;i<N;i++)
	{
		if (Q.empty()) // 위상정렬 불가
		{
			cout << 0;
			return 0;
		}

		int curr = Q.front(); Q.pop();
		result.push_back(curr);

		for (int adjNode : adjList[curr])
		{
			indegree[adjNode] -= 1;

			if (indegree[adjNode] == 0)
			{
				Q.push(adjNode);
			}
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
}