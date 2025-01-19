#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <cassert>
#include <map>
#include <set>
using namespace std;

typedef pair<int, vector<int>> PQNode;
#define INF 1000000

struct control
{
	int l, r, c;
};

int N, M;
vector<int> arr;
vector<control> controls;
set<vector<int>> visitedArrays;


int Dijkstra()
{
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> PQ;
	
	map<vector<int>, int> dist;

	dist[arr] = 0;
	PQ.push(PQNode(0, arr));

	while (!PQ.empty())
	{
		PQNode curr = PQ.top(); PQ.pop();

		vector<int> currArr = curr.second;
		if (visitedArrays.find(currArr) != visitedArrays.end())
			continue;
		visitedArrays.insert(currArr);

		//cout << "sort check start" << endl;
		bool isSorted = true;
		for (int i = 1; i < currArr.size(); i++)
		{
			if (currArr[i - 1] > currArr[i])
			{
				isSorted = false;
				break;
			}
		}
		//cout << "sort check end" << endl;
		if (isSorted)
			return dist[currArr];


		for (auto control : controls)
		{
			vector<int> newArr = currArr;
			swap(newArr[control.l - 1], newArr[control.r - 1]);

			int cost = control.c;

			if (dist.find(newArr) == dist.end() || dist[currArr] + cost < dist[newArr])
			{
				dist[newArr] = dist[currArr] + cost;
				PQ.push(PQNode(dist[newArr], newArr));
			}
		}
	}

	return INF;
}

void Input()
{
	cin >> N;
	arr.resize(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		control c;
		cin >> c.l >> c.r >> c.c;
		controls.push_back(c);
	}
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();

	int ret = Dijkstra();

	if (ret == INF)
		cout << -1;
	else
		cout << ret;
}
