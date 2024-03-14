#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string string1;
string string2;
string string3;

int LCS[101][101][101]; // [string1][string2][string3]

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			for(int k=0;k<101;k++)
				LCS[i][j][k] = 0;

	cin >> string1;
	cin >> string2;
	cin >> string3;

	for (int i = 1; i <= string1.length(); i++)
	{
		for (int j = 1; j <= string2.length(); j++)
		{
			for (int k = 1; k <= string3.length(); k++)
			{
				if (string1[i - 1] == string2[j - 1] && string2[j-1] == string3[k-1])
				{
					LCS[i][j][k] = LCS[i - 1][j - 1][k-1] + 1;
				}
				else
				{
					LCS[i][j][k] = std::max({LCS[i - 1][j][k], LCS[i][j - 1][k], LCS[i][j][k-1]});
				}
			}
		}
	}

	cout << LCS[string1.length()][string2.length()][string3.length()] << "\n";
}