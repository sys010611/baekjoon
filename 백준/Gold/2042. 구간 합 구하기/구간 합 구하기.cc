#include <iostream>
#include <cmath>
using namespace std;

int N,M,K;

#define int long long

long long arr[2097152]; // 세그먼트 트리

void PrintTree(int arrLen)
{
	for (int i = 0; i <= arrLen; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void UpdateTree(int idx)
{
	idx /= 2;

	while (idx > 0)
	{
		arr[idx] = arr[idx*2] + arr[idx*2 + 1];
		idx /= 2;
	}
}

int sum(int L, int R, int nodeL, int nodeR, int nodeIdx)
{/*
	cout << "nodeIdx : " << nodeIdx << endl;
	cout << "nodeL : " << nodeL << endl;
	cout << "nodeR : " << nodeR << endl;*/

	if (R < nodeL || nodeR < L) // 노드의 구간과 아예 안겹치는 경우
	{
		//cout <<"아예안겹칩" << endl;
		return 0;
	}

	if (L <= nodeL && R >= nodeR) // 노드의 구간을 완전히 덮는 경우
	{
		//cout << "완전히 겹침" << endl;
		return arr[nodeIdx];
	}

	// 그 외: 노드의 구간이 구하고자 하는 구간과 일부만 겹침 -> 구간을 더 쪼개야함
	//cout << "애매" << endl;
	long long mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeL, mid, nodeIdx * 2) + sum(L, R, mid + 1, nodeR, nodeIdx * 2 + 1);

}

signed main()
{
	cin >> N >> M >> K;
	
	fill(arr, arr+ 2097152, 0);

	int realN = 1; // 숫자의 개수를 2의 제곱수로 불린 것
	int treeMaxLevel = 0;
	while (realN < N)
	{
		realN *= 2;
		treeMaxLevel++;
	}

	//cout << "realN: " << realN << endl;
	//cout << "treeMaxLevel: " << treeMaxLevel << endl;

	int arrLen = pow(2, treeMaxLevel + 1) - 1;

	for (int i = realN, j = 0; j < N; i++, j++)
	{
		cin >> arr[i];
	}

	//PrintTree(arrLen);

	for (int i = realN; i <= arrLen; i++)
	{
		UpdateTree(i);
	}

	//PrintTree(arrLen);

	long long a, b, c;
	for (int t = 0; t < M + K; t++)
	{
		cin >> a >> b >> c;

		if (a == 1) // 숫자 변경 (b번째를 c로)
		{
			int idx = realN + b - 1; // arr에서 변경할 숫자의 실제 인덱스
			
			arr[idx] = c;

			UpdateTree(idx);
			//PrintTree(arrLen);
		}
		else // 구간합 구하기 (b부터 c까지)
		{
			//printf("%d 부터 %d까지 구간합 구하기\n" , b, c);
			cout << sum(b, c, 1, realN, 1) << endl;
		}
	}
}