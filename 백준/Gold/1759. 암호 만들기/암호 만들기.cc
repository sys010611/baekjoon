#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C; //L: 암호의 길이 C: 알파벳의 개수
char apt[15];
char PW[15];

void backtrack(int pos, int prev);

int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> apt[i];
	}
	sort(apt, apt+C); //알파벳 정렬

	backtrack(0, -1);
}

void backtrack(int pos, int prev)
{
	if (pos == L) //모든 자리 채워짐
	{
		int vowelCount = 0;
		int consonantCount = 0;
		for (int i = 0; i < L; i++)
		{
			switch (PW[i])
			{
				case 'a': case 'i': case 'e': case'o': case'u':
					vowelCount++;
					continue;
				default:
					consonantCount++;
			}
		}

		if (vowelCount >= 1 && consonantCount >= 2) //모음 최소 1개, 자음 최소 2개
		{
			for(int i=0;i<L;i++)
				cout << PW[i];
			cout << endl;
			
			return;
		}
	}

	for (int i = prev + 1; i < C; i++)
	{
		PW[pos] = apt[i];
		backtrack(pos+1, i);
	}

}