#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n,m;
int p[500000];
int result = 0;


int find(int n)
{
	if (p[n] == -1)
		return n;
	else
		return find(p[n]);
}

void merge(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);

	p[rootB] = rootA;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(p, -1, sizeof(p));
	
	cin >> n >> m;

	int a,b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		//cout << "A: " << a << endl;
		//cout << "B: " << b << endl;

		if(result != 0)
			continue;

		if (find(a) != find(b))
		{
			merge(a, b);
			//cout << "병합 완료" << endl;
		}
		else
		{
			//cout << i+1 << "번째 사이클 발생" << endl;
			result = i + 1;
		}
	}

	cout << result;
}