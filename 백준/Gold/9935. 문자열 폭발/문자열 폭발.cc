#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

stack<pair<char, int>> S;

int main()
{
	string sentence;
	string pattern;
	string result_reversed;
	
	cin >> sentence;
	cin >> pattern;

	int overlapCount = 0;
	for (int i = 0; i < sentence.length(); i++)
	{
		char c = sentence[i];

		if(c == pattern[overlapCount])
			overlapCount++;
		else
		{
			if(c == pattern[0])
				overlapCount = 1;
			else
				overlapCount = 0;
		}

		S.push({c, overlapCount});

		if (overlapCount == pattern.length())
		{
			for (int j = 0; j < pattern.length(); j++)
			{
				S.pop();
			}

			if(!S.empty())
				overlapCount = S.top().second;
			else
				overlapCount = 0;
		}
	}

	while (!S.empty())
	{
		result_reversed.push_back(S.top().first);
		S.pop();
	}


	if (result_reversed.empty())
	{
		cout << "FRULA";
	}
	else
	{
		for (int i = result_reversed.size() - 1; i > -1; i--)
		{
			cout << result_reversed[i];
		}
	}
}