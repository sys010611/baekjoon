#include <iostream>
#include <queue>
#include <unordered_set>
#include <cstring>
#include <set>
using namespace std;

int N, M;
vector<int> A, B;
int dp[101][101];
vector<int> ret;


void FindBiggestCommonNumber(int aStart, int bStart)
{
	//printf("astart : %d , bstart : %d\n", aStart, bStart);

	int aIdx = -1;
	int bIdx = -1;

	int biggestCommonNumber = -1;
	for (int i = aStart+1; i < A.size(); i++)
	{
		for (int j = bStart+1; j < B.size(); j++)
		{
			if (A[i] == B[j])
			{
				if (A[i] > biggestCommonNumber)
				{
					biggestCommonNumber = A[i];
					aIdx = i;
					bIdx = j;
				}
			}
		}
	}

	if(aIdx==-1) return;
	ret.push_back(biggestCommonNumber);
	//cout << biggestCommonNumber << "added " << endl;
	FindBiggestCommonNumber(aIdx, bIdx);

}

signed main()
{
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	cin >> M;
	B.resize(M);
	for (int i = 0; i < M; i++)
		cin >> B[i];

	FindBiggestCommonNumber(-1, -1);

	if (ret.empty())
	{
		cout << 0;
	}
	else
	{
		cout << ret.size() << endl;
		for (auto item : ret)
		{
			cout << item << " ";
		}
	}
}
