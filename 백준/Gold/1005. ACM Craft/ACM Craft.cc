#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

//void PrintGraph()
//{
//	cout << "adjList: " << endl;
//	for (int i = 1; i <= N; i++)
//	{
//		cout << i << "->";
//		for (auto it = adjList[i].begin(); it != adjList[i].end(); it++)
//		{
//			cout << *it << ", ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	cout << "indegree : " << endl;
//	for (int i = 1; i <= N; i++)
//	{
//		cout << i << ": " << indegree[i] << endl;
//	}
//	cout << endl;
//}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int N, K, W;
		vector<int> indegree;
		vector<vector<int>> adjList;
		vector<int> cost;

		cin >> N >> K;

		adjList.resize(N + 1);
		indegree.resize(N + 1);
		fill(indegree.begin(), indegree.end(), 0);
		cost.resize(N + 1);

		for (int i = 1; i <= N; i++)
		{
			cin >> cost[i];
		}
		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			indegree[y]++;
			adjList[x].push_back(y);
		}
		cin >> W;

		vector<int> result;
		result.resize(N + 1);

		//위상 정렬
		queue<int> Q;
		for (int i = 1; i <= N; i++)
		{
			if (indegree[i] == 0)
			{
				Q.push(i);
				result[i] = cost[i];
			}
		}

		for (int i = 0; i < N; i++)
		{
			int curr = Q.front(); Q.pop();

			for (int adjNode : adjList[curr])
			{
				indegree[adjNode] -= 1;

				if (indegree[adjNode] == 0)
				{
					Q.push(adjNode);
				}

				result[adjNode] = max(result[adjNode], result[curr] + cost[adjNode]);
			}
		}

		cout << result[W] << endl;
	}
}