#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<float,float> P;

float GetDistance(P a, P b)
{
	return sqrt(pow(a.first-b.first, 2) + pow(a.second - b.second, 2));
}

class Graph
{
public:
	int N;
	vector<vector<P>> adjList; //<거리, 번호>
	vector<bool> visited;
	vector<P> position;

	Graph(int n)
	{
		N = n;
		adjList.resize(N);
		visited.resize(N);
		position.resize(N);
	}

	void SetEdge()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				float dist = GetDistance(position[i], position[j]);

				adjList[i].push_back(P(dist, j));
				adjList[j].push_back(P(dist, i));
			}
		}
	}

	void PrintEdge()
	{
		for (int i = 0; i < N; i++)
		{
			for (auto it = adjList[i].begin(); it != adjList[i].end(); it++)
			{
				cout << i << " -> " << it->second << ": " << it->first << endl;
			}
		}
	}

	float Prim()
	{
		float result = 0;
		priority_queue<P, vector<P>, greater<P>> PQ;

		PQ.push(P(0, 0));

		int edgeCount = -1;

		while (edgeCount < N - 1)
		{
			P curr = PQ.top(); PQ.pop();
			
			if(visited[curr.second])
				continue;

			visited[curr.second] = true;

			edgeCount++;
			result += curr.first;

			int currNode = curr.second;
			//cout << "Node " << currNode << "포함" << endl;
			//cout << "현재 비용: " << result << endl;

			for (P& next : adjList[currNode])
			{
				if (!visited[next.second])
				{
					PQ.push(next);
				}
			}
		}
		return result;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	Graph G(n);

	float x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		G.position[i] = P(x,y);
	}
	G.SetEdge();
	//G.PrintEdge();

	cout << G.Prim();
}

