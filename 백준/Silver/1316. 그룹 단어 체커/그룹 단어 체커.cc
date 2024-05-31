#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int count = 0;
	int N;
	cin >> N;
	while (N--)
	{
		bool used[26];
		fill(used, used+26, false);

		string str;
		cin >> str;

		char prev;
		prev = str[0];
		used[prev - 'a'] = true;


		bool success = true;
		for (int i = 1; i < str.length(); i++)
		{
			if(str[i] == prev)
				continue;
			else // 이전거랑 다른게 나옴
			{
				char curr = str[i];
				if (used[curr - 'a'] == true)
				{
					success = false;
					break;
				}
				else
				{
					used[curr - 'a'] = true;
					prev = curr;
					continue;
				}
			}
		}

		if(success) count++;
	}

	cout << count;
}