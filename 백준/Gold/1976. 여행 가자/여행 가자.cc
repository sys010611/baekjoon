#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int p[201];
int input;

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
	if(p[node] == -1) // 루트 노드면 그대로 리턴
		return node;
	else
		return find(p[node]); // 아니면 계속 부모로 올라가기
}

void merge(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);

	p[rootA] = rootB;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(p, -1, sizeof(p));

	cin >> N >> M;
	for (int cityA = 1; cityA <= N; cityA++)
	{
		for (int cityB = 1; cityB <= N; cityB++)
		{
			cin >> input;
			if (input == 1)
			{
				if(find(cityA) != find(cityB))
					merge(cityA, cityB);
			}
		}
	}

	//PrintP();

	int prev, curr;
	cin >> prev;
	for (int i = 1; i < M; i++)
	{
		cin >> curr;
		if (find(prev) != find(curr))
		{
			cout << "NO";
			return 0;
		}

		prev = curr;
	}

	cout << "YES";
	return 0;
}

