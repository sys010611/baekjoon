#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 1000000;

string T, P;
int N; // 텍스트의 길이
int M; // 패턴의 길이
int fail[MAX];
vector<int> posList;

void KMP()
{
	for (int i = 0, j = 0; i < N; i++)
	{
		while (j > 0 && T[i] != P[j]) // 불일치할 경우
		{
			j = fail[j-1]; // j를 계속해서 업데이트
		}

		if (T[i] == P[j])
		{
			//단어 전체를 찾은 경우
			if (j == M - 1)
			{
				posList.push_back(i - j);
				j = fail[j]; // 이어서 탐색
			}
			else
			{
				j++;
			}
		}
	}
}

void MakeFailArr()
{
	memset(fail, 0, sizeof(fail));
	for (int i = 1, j = 0; i < M; i++)
	{
		while (j > 0 && P[i] != P[j])
		{
			j = fail[j-1];
		}

		if (P[i] == P[j])
		{
			j++;
			fail[i] = j;
		}
	}

	//for (int i = 0; i < M; i++)
	//{
	//	printf("fail[%d] : %d\n", i, fail[i]);
	//}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, T);
	getline(cin, P);

	N = T.length();
	M = P.length();

	MakeFailArr();
	KMP();

	cout << posList.size() << "\n";
	for (auto it : posList)
	{
		cout << it+1 << "\n";
	}
}
