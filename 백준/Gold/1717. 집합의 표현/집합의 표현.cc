#include <iostream>
#include <algorithm>
using namespace std;

int p[1000001]; //각 노드의 부모 노드

int find(int node)
{
	if (p[node] == -1)
	{
		return node;
	}
	else
	{
		return p[node] = find(p[node]);
	}
}

void merge(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);

	if(rootA == rootB) return;

	p[rootB] = rootA;
}

void check(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);

	if(rootA == rootB)
		cout << "yes" << "\n";
	else
		cout << "no" << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(p,p+1000001, -1);

	int n,m;
	cin >> n >> m;

	int command,a,b;
	for (int i = 0; i < m; i++)
	{
		cin >> command >> a >> b;

		if (command == 0)
		{
			merge(a,b);
		}
		else
		{
			check(a,b);
		}
	}

	for (int i = 0; i <= n; i++)
	{
		cout << p[i] << " ";
	}
	return 0;
}