#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

string S, T;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S >> T;

	while (S.length() != T.length())
	{
		if (T[T.length() - 1] == 'A')
		{
			T.erase(T.length()-1, T.length());
		}
		else if (T[T.length() - 1] == 'B')
		{
			T.erase(T.length() - 1, T.length());
			reverse(T.begin(), T.end());
		}
	}

	if(S == T)
		cout << 1;
	else
		cout << 0;
}