#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int fail[1000001];
int N;
string s;

void KMP()
{

}

void MakeFailArr()
{
	memset(fail, 0, sizeof(fail));

	for (int i = 1, j = 0; i < N; i++)
	{
		//cout << "i : " << i << " j : " << j << endl;
		while (j > 0 && s[i] != s[j])
		{
			j = fail[j-1];
		}

		if (s[i] == s[j])
		{
			//cout << "일치 문자 발견 " << endl;
			fail[i] = ++j;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		getline(cin, s);

		if(s == ".")
			return 0;

		N = s.length();

		MakeFailArr();

		//for (int i = 0; i < N; i++)
		//{
			//printf("fail[%d] : %d\n", i, fail[i]);
		//}

		//cout << "fail의 마지막 원소 : " << fail[N - 1] << endl;

		int result = N / (N - fail[N - 1]);
		//cout << "나눠진 개수 : " << result << endl;

		int n = N / result; //나눠진 문자열의 길이
		//cout << "나눠진 문자열의 길이:  " << n << endl;

		if (s[n - 1] != s[N - 1]) // 반복되지 않는 문자열이었을 경운
		{
			cout << 1 << endl;
		}
		else
		{
			cout << result << endl;
		}
	}

}
