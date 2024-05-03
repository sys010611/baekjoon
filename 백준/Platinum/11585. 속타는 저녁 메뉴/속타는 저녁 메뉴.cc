#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

string S; // sentence
string W; // word
int N;

int numerator = 0;

int fail[2000000];

void MakeFailArr()
{
	memset(fail, 0, sizeof(fail));

	for (int i = 1, j = 0; i < N; i++)
	{
		while (j > 0 && W[i] != W[j])
		{
			j = fail[j - 1];
		}

		if (W[i] == W[j])
		{
			fail[i] = ++j;
		}
	}
}

void KMP()
{
	for (int i = 1, j = 0; i < 2 * N; i++)
	{
		while (j > 0 && S[i] != W[j])
		{
			j = fail[j-1];
		}

		if (S[i] == W[j])
		{
			if (j == N - 1) // 원하는 단어를 찾았을 경우
			{
				numerator++;
			}

			j++;
		}
	}
}

int GCD(int a, int b)
{
	if(b == 0)
		return a;
	else
		return GCD(b, a%b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char input;
		cin >> input;

		W.push_back(input);
	}

	for (int i = 0; i < N; i++)
	{
		char input;
		cin >> input;

		S.push_back(input);
	}
	S = S+S;

	MakeFailArr();
	KMP();

	int gcd = GCD(numerator, N);
	
	cout << numerator/gcd << "/" << N/gcd;
}