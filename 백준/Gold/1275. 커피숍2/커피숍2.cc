#include <iostream>
#include <vector>
using namespace std;

int _n, Q, x, y, a, b;
int N;

long long segmentTree[262144];

void ConstructTree(int leafNode)
{
	leafNode /= 2;
	while (leafNode > 0)
	{
		segmentTree[leafNode] = segmentTree[leafNode * 2] + segmentTree[leafNode * 2 +1];
		leafNode /= 2;
	}
}

long long Sum(int L, int R, int nodeNum, int segmentL, int segmentR)
{
	//cout << "현재 노드 번호: "<< nodeNum << endl;
	//cout << "현재 노드 구간: " << segmentL << "~" << segmentR << endl;

	if (R < segmentL || segmentR < L) // 완전히 틀린 구간
	{
		//cout << "완전히 틀린 구간" << endl;
		return 0;
	}
	
	if (L <= segmentL && segmentR <= R) // 노드의 구간이 구하려는 구간에 완전히 포함
	{
		//cout << "노드의 구간이 구하려는 구간에 완전히 포함, 구간합 : " << segmentTree[nodeNum] << endl;
		return segmentTree[nodeNum];
	}

	//이외
	int mid = (segmentL + segmentR) / 2;
	return Sum(L, R, nodeNum * 2, segmentL, mid) + Sum(L,R,nodeNum*2+1, mid+1, segmentR);
}

void PrintSegmentTree()
{
	cout << endl;
	for (int i = 1; i <= 2 * N - 1; i++)
		cout << "node " << i << ": " << segmentTree[i] << endl;
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> _n >> Q;

	N = 1;
	while(N < _n)
		N *= 2;

	for (int i = 0; i < _n; i++)
		cin >> segmentTree[N + i];

	// 빠른 초기화
	for (int i = N - 1; i > 0; i--)
	{
		segmentTree[i] = segmentTree[2*i] + segmentTree[2*i+1];
	}

	//for (int leafNode = N; leafNode <= 2 * N - 1; leafNode++)
	//{
	//	ConstructTree(leafNode);
	//}

	for (int i = 0; i < Q; i++)
	{
		cin >> x >> y >> a >> b;

		if (x > y)
		{
			cout << Sum(y - 1, x - 1, 1, 0, N - 1) << "\n";
		}
		else
		{
			cout << Sum(x - 1, y - 1, 1, 0, N - 1) << "\n";
		}

		segmentTree[N + a - 1] = b;
		ConstructTree(N + a - 1);

		//PrintSegmentTree();
	}
}