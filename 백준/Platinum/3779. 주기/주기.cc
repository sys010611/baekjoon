#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

const int MAX = 1000001;

int N;
int fail[MAX];
string S;

void MakeFailArr(const string& S)
{
	fill(fail, fail+ MAX, 0);

	for (int i = 1, j = 0; i < N; i++)
	{
		while (j > 0 && S[i] != S[j])
		{
			j = fail[j-1];
		}

		if (S[i] == S[j])
		{
			fail[i] = ++j;
		}
	}

	//for (int i = 0; i < N; i++) printf("fail[%d] : %d\n", i, fail[i]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (unsigned long long t = 1;; t++)
	{

		cin >> N;

		if(N == 0)
			return 0;

		cin >> S;

		cout << "Test case #" << t << "\n";


		MakeFailArr(S);

		int wordLen = 0;
		int prefixLen = 0;

		for (int i = 1; i <= N; i++)
		{
			int K = (i + 1) / (i+1 - fail[i]);
			if ((i + 1) % (i + 1 - fail[i]) == 0 && K > 1)
				cout << i+1 << " " << K << "\n";
		}
		cout << endl;
	}
}