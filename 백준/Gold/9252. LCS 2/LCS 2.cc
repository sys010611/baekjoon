#include <iostream>
#include <string>
using namespace std;

string string1;
string string2;

int LCS[1001][1001]; // 행은 string1, 열은 string2

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=0;i<1001;i++)
		for(int j=0;j<1001;j++)
			LCS[i][j] = 0;

	cin >> string1;
	cin >> string2;

	for (int i = 1; i <= string1.length(); i++)
	{
		for (int j = 1; j <= string2.length(); j++)
		{
			if (string1[i - 1] == string2[j - 1])
			{
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else
			{
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
	}

	//for (int i = 0; i <= string1.length(); i++)
	//{
	//	for (int j = 0; j <= string2.length(); j++)
	//		cout << LCS[i][j] << " ";
	//	cout << endl;
	//}

	cout << LCS[string1.length()][string2.length()] << "\n";

	string resultString;

	int i = string1.length();
	int j = string2.length();
	while (i > 0 && j > 0)
	{
		if (LCS[i][j] == LCS[i - 1][j])
		{
			i--;
		}
		else if (LCS[i][j] == LCS[i][j - 1])
		{
			j--;
		}
		else
		{
			resultString.insert(0, 1, string1[i-1]);
			i--;
			j--;
		}
	}

	cout << resultString;
}