#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <set>
#include <queue>
using namespace std;

#define int long long

typedef pair<int,int> P;
const int MinusInf = INT_MIN;

int N, M;
vector<vector<P>> adjList;
vector<vector<int>> adjList_reversed;

int cost[101];
int prevNode[101];
bool isReachableFromDest[101];

void BFSFromDest()
{
	isReachableFromDest[N] = true;

	bool visited[101];
	fill(visited, visited + 101, false);

	queue<int> Q;
	Q.push(N);
	visited[N] = true;

	while (!Q.empty())
	{
		int curr = Q.front(); Q.pop();

		for (auto adj : adjList_reversed[curr])
		{
			if (!visited[adj])
			{
				Q.push(adj);
				isReachableFromDest[adj] = true;
				//cout << adj << " : 목적지로 이어짐 " << endl;
				visited[adj] = true;
			}
		}
	}
}

signed main()
{
	cin >> N >> M;

	fill(cost, cost+101, MinusInf);
	cost[1] = 0;
	prevNode[1] = -1;

	adjList.resize(N + 1);
	adjList_reversed.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		adjList[A].push_back(P(B, C));
		adjList_reversed[B].push_back(A);
	}

	BFSFromDest();

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (auto adjNode : adjList[j])
			{
				if (cost[j] != MinusInf)
				{
					if (cost[adjNode.first] < cost[j] + adjNode.second)
					{
						cost[adjNode.first] = cost[j] + adjNode.second;
						prevNode[adjNode.first] = j;

						if (i == N-1) // 음의 사이클 발견
						{
							if (isReachableFromDest[adjNode.first])
							{
								cout << -1;
								return 0;
							}
						}
					}
				}
			}
		}
	}

	//for (int i = 1; i <= N; i++)
	//{
	//	printf("prev of %d : %d\n", i, prevNode[i]);
	//}

	stack<int> S;
	int curr = N;
	while (curr != -1)
	{
		//cout << "curr : " << curr << endl;
		S.push(curr);
		curr = prevNode[curr];
	}

	while (!S.empty())
	{
		cout << S.top() << " ";
		S.pop();
	}
}
