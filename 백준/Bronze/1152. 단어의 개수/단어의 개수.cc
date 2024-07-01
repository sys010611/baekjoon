#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;

	getline(cin, s);

	bool prevWordEnded = true;

	int result = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			prevWordEnded = true;
		}
		else
		{
			if (prevWordEnded)
			{
				result++;
				prevWordEnded = false;
			}
		}
	}

	cout << result;
}