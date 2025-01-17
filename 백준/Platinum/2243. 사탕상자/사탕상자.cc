#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
using namespace std;

#define int long long

int segTree[5000000];
int n;
int leafCount;

void update(int treeIdx)
{
	//cout << "TreeIdx : " << treeIdx << endl;
	treeIdx /= 2;
	while (treeIdx >= 1)
	{
		segTree[treeIdx] = segTree[treeIdx * 2] + segTree[treeIdx * 2 + 1];
		treeIdx /= 2;
	}
}

int erase(int currNodeIdx,int value)
{
	if (leafCount <= currNodeIdx && currNodeIdx <= leafCount * 2 - 1)
	{
		cout << currNodeIdx - leafCount + 1 << '\n';
		segTree[currNodeIdx]--;
		return currNodeIdx; // 조정한 노드의 인덱스를 반환
	}

	//cout << "currNodeIdx : " << currNodeIdx << endl;

	int leftIdx = currNodeIdx * 2;
	int rightIdx = currNodeIdx * 2 + 1;

	int leftTreeSize = segTree[leftIdx];
	//cout << "leftTreeSize : " << leftTreeSize << endl;

	if (leftTreeSize >= value)
	{
		//cout << "TO LEFT" << endl;
		return erase(leftIdx, value);
	}
	else
	{
		//cout << "TO RIGHT" << endl;
		return erase(rightIdx, value - leftTreeSize);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(segTree, 0, sizeof(segTree));

	leafCount = 1;
	while (leafCount < 1000000)
	{
		leafCount *= 2;
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int A, B;
		cin >> A >> B;

		if (A == 1) // n번째 사탕 빼기
		{
			int modifiedNodeNo = erase(1, B);
			update(modifiedNodeNo);
		}
		else if (A == 2) // 맛이 i인 사탕 넣기 / 빼기
		{
			int C;
			cin >> C;

			int treeIdx = B + leafCount - 1;
			segTree[treeIdx] += C;
			update(treeIdx);
		}

		//cout << "사탕 현황" << endl;
		//for (int i = leafCount; i <= leafCount + 8; i++)
		//{
		//	cout << segTree[i] << " ";
		//}
		//cout << endl;
	}
}