#include <iostream>

using namespace std;

long long segmentTree[2100000];

void PrintTree(int realN)
{
	for (int i = 1; i <= 2 * realN - 1; i++)
	{
		cout << segmentTree[i] << " ";
	}
	cout << endl;
}

void UpdateTree(int idx)
{
	idx /= 2;

	while (idx > 0)
	{
		segmentTree[idx] = segmentTree[idx*2] % 1000000007 * segmentTree[idx*2 + 1] % 1000000007;

		idx /= 2;
	}
}

void ConstructTree(int realN)
{
	for (int i = realN-1; i >= 1; i--)
	{
		segmentTree[i] = segmentTree[i*2] % 1000000007 * segmentTree[i*2 + 1] % 1000000007;
	}
}

long long GetMul(int L, int R, int nodeL, int nodeR, int nodeNo)
{
	//cout << "현재 노드번호: " << nodeNo << endl;
	//cout << "현재 노드 범위: " << nodeL << " " << nodeR << endl;
	if(R < nodeL || L > nodeR) // 노드의 범위 밖인 경우
		return 1;

	if (L <= nodeL && nodeR <= R) // 범위가 노드를 완전히 포함하는 경우
		return segmentTree[nodeNo] % 1000000007;

	// 범위가 노드에 일부만 겹침
	int mid = (nodeL + nodeR) / 2;
	return (GetMul(L, R, nodeL, mid, nodeNo*2) * GetMul(L, R, mid+1, nodeR, nodeNo*2 + 1)) % 1000000007;
}

int main()
{
	fill(segmentTree, segmentTree + 2100000, 1);

	int N, M, K;

	cin >> N >> M >> K;

	int realN = 1; //N을 2의 제곱수로 늘린 것
	while (realN <= N)
	{
		realN *= 2;
	}

	//cout << "realN: " << realN << endl;

	for (int i = realN; i < realN + N; i++)
	{
		cin >> segmentTree[i];
	}

	//PrintTree(realN);

	//for (int i = realN; i < realN + N; i++)
	//{
	//	UpdateTree(i);
	//}

	ConstructTree(realN);

	//PrintTree(realN);

	int a,b,c;
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		
		if (a == 1)
		{
			// 숫자 바꾸기
			segmentTree[realN + b - 1] = c;
			UpdateTree(realN + b - 1);

			//PrintTree(realN);

		}
		else if (a == 2)
		{
			// 구간곱 구하기
			//cout << "구할 범위: " << b << " " << c << endl;
			cout << GetMul(b, c, 1, realN, 1) << endl;
		}

	}
}