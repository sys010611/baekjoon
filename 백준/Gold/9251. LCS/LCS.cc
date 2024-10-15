#include <iostream>
#include <string.h>
using namespace std;

string string1;
string string2;

int LCS[1001][1001]; // 행은 string1, 열은 string2

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(LCS[0], LCS[1000], 0);

	cin >> string1;
	cin >> string2;

	for (int i = 1; i <= string1.length(); i++)
	{
		for (int j = 1; j <= string2.length(); j++)
		{
			if (string1[i-1] == string2[j-1])
			{
				LCS[i][j] = LCS[i-1][j-1] + 1;
			}
			else
			{
				LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
			}
		}
	}

	cout << LCS[string1.length()][string2.length()];
}