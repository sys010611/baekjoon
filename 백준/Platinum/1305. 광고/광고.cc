#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 1000000;

int L;
string S;
int fail[MAX];

/// <summary>
/// fail 배열을 채운다.
/// </summary>
void KMP()
{
	for (int i = 1, j = 0; i < L; i++)
	{
		//cout << "i : " << i << ", j : " << j << endl;
		if (j > 0 && S[i] != S[j])
		{
			j = fail[j-1];
		}

		if (S[i] == S[j])
		{
			//cout << "문자 일치 " << endl;
			fail[i] = j+1;
			j++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> L;
	cin >> S;

	memset(fail, 0, sizeof(fail));

	KMP();

	//for (int i = 0; i < L; i++)
	//{
	//	printf("fail[%d] : %d\n", i, fail[i]);
	//}

	//int maxFailValue = *max_element(fail, fail + MAX);
	int lastFailValue = fail[L-1];

	cout << L - lastFailValue;
}