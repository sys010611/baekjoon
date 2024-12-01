#include <iostream>
#include <climits>
using namespace std;

#define SIZE 300000

int _n, N, M;

int minSegTree[SIZE];
int maxSegTree[SIZE];

void PrintMinSegTree()
{
	for (int i = 1; i <= 2*N; i++)
	{
		cout << minSegTree[i] << " ";
	}
	cout << endl;
}

void insert(int input, int idx)
{
	int newIdx = idx + N;
	//cout << "NEWIDX : " << newIdx << endl;

	int p = newIdx;
	minSegTree[p] = input;
	p /= 2;
	while (p > 0)
	{
		minSegTree[p] = min(minSegTree[p * 2], minSegTree[p * 2 + 1]);
		p /= 2;
	}

	int q = newIdx;
	maxSegTree[q] = input;
	q /= 2;
	while (q > 0)
	{
		maxSegTree[q] = max(maxSegTree[q * 2], maxSegTree[q * 2 + 1]);
		q /= 2;
	}
}

int queryMin(int L, int R, int nodeNum, int nodeL, int nodeR)
{
	//printf("%d, %d, %d, %d, %d\n", L, R, nodeNum, nodeL, nodeR);
	// 겹치지 않는 경우
	if (nodeR < L || R < nodeL)
	{
		//cout << "겹치지않음" << endl;
		return INT_MAX;
	}

	// 포함하는 경우
	if (L <= nodeL && nodeR <= R)
	{
		//cout << "포함";
		//cout << "ret : " << minSegTree[nodeNum] << endl;
		return minSegTree[nodeNum];
	}

	// 애매하게 겹치는 경우
	//cout << "일부 겹침" << endl;
	int mid = (nodeL + nodeR) / 2;
	return min(queryMin(L, R, nodeNum * 2, nodeL, mid), queryMin(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}

int queryMax(int L, int R, int nodeNum, int nodeL, int nodeR)
{
	// 겹치지 않는 경우
	if (nodeR < L || R < nodeL)
	{
		return INT_MIN;
	}

	// 포함하는 경우
	if (L <= nodeL && nodeR <= R)
	{
		return maxSegTree[nodeNum];
	}

	// 애매하게 겹치는 경우
	int mid = (nodeL + nodeR) / 2;
	return max(queryMax(L, R, nodeNum * 2, nodeL, mid), queryMax(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> _n >> M;

	N = 1;
	while (N < _n)
	{
		N *= 2;
	}
	//cout << "N : " << N << endl;

	fill(minSegTree, minSegTree + SIZE, INT_MAX);
	fill(maxSegTree, maxSegTree + SIZE, INT_MIN);

	for (int i = 0; i < _n; i++)
	{
		int input;
		cin >> input;

		insert(input, i);
	}

	//PrintMinSegTree();

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << queryMin(a, b, 1, 1, N) << " ";
		cout << queryMax(a, b, 1, 1, N) << '\n';
	}
}
