#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, k;
int p[10001];
int cost[10001];
int visited[10001];

void PrintP()
{
	cout << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl << endl;
}

int find(int node)
{
	if(p[node] < 0) // 코스트를 담고 있는 루트 노드면 그대로 리턴
		return node;
	else
		return find(p[node]); // 아니면 계속 부모로 올라가기
}

void merge(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);

	p[rootB] = max(p[rootB], p[rootA]); // 루트를 맡을 노드에 두 컴포넌트의 최소 코스트를 저장.
	p[rootA] = rootB; // A를 B에 붙이기.
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(p, 0, sizeof(p));

	cin >> N >> M >> k;

	for (int i = 1; i <= N; i++)
	{
		int cost;
		cin >> cost;
		p[i] = -cost;
	}

	for (int i = 0; i < M; i++)
	{
		int v, w;
		cin >> v >> w;

		if (find(v) != find(w))
		{
			merge(v, w);
		}
	}

	int result = 0;
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= N; i++) // 모든 친구
	{
		int root = find(i);
		if (!visited[root]) // 아직 고려하지 않은 컴포넌트라면
		{
			result += p[root]; //코스트를 누적합
			k += p[root]; //현재 돈에서 친구비 빼기

			if (k < 0) // 돈이 부족한 상황이었다면
			{
				cout << "Oh no";
				return 0;
			}
			visited[root] = true;
		}
	}

	cout << -result;	
	return 0;
}

