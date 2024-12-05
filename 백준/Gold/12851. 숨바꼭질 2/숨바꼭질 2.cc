#include <iostream>
#include <queue>
#include <unordered_set>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

#define MAX 300000
#define INF INT_MAX

int N, K;
int visitTime[MAX];
int visitCount[MAX];

void BFS(int start)
{
	queue<int> Q;

	visitTime[start] = 0;
	visitCount[start] = 1;

	if (start == K)
	{
		return;
	}

	Q.push(start);

	int currTime = 1;

	while (!Q.empty())
	{
		int qSize = Q.size();
		//cout << "currTime : " << currTime << endl;
		while (qSize--)
		{
			int curr = Q.front(); Q.pop();
			//cout << "curr : " << curr << endl;

			if (curr == K)
			{
				//cout << "FOUND" << endl;
				return;
			}

			int next;
			next = curr+1;
			if (next < MAX && currTime <= visitTime[next])
			{
				if(visitTime[next] == INF)
					Q.push(next);

				visitTime[next] = currTime;
				visitCount[next] += visitCount[curr];
			}
			next = curr-1;
			if (next >=0 && currTime <= visitTime[next])
			{
				if (visitTime[next] == INF)
					Q.push(next);

				visitTime[next] = currTime;
				visitCount[next] += visitCount[curr];
			}
			next = curr * 2;
			if (next < MAX && currTime <= visitTime[next])
			{
				if (visitTime[next] == INF)
					Q.push(next);

				visitTime[next] = currTime;
				visitCount[next] += visitCount[curr];
			}
		}
		currTime++;
	}
	//cout << "Q EMPTY" << endl;
}

signed main()
{
	fill(visitTime, visitTime + MAX, INF);
	memset(visitCount, 0, sizeof(visitCount));

	cin >> N >> K;

	BFS(N);

	cout << visitTime[K] << endl << visitCount[K];
}
