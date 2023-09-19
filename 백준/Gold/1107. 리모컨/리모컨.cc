#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

set<int> brokenNum;

const int INF = 100000000;

bool checkValid(int number)
{
	if(number < 0)
		return false;

	do
	{
		if (find(brokenNum.begin(), brokenNum.end(), number % 10) != brokenNum.end())
		{
			return false;
		}

		number /= 10;
	} while (number > 0);

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int n, m;
	cin >> n >> m;

	int input;
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		brokenNum.insert(input);
	}

	int result1 = abs(n - 100);

	if (m == 10)
	{
		cout << result1;
		return 0;
	}

	int result2;
	for (int i = 0; i < INF; i++)
	{
		bool plusValid = checkValid(n + i);
		bool minusValid = checkValid(n - i);

		if (plusValid && minusValid)
		{
			result2 = min(to_string(n + i).length(), to_string(n - i).length()) + i;
			break;
		}

		if (plusValid)
		{
			result2 = to_string(n + i).length() + i;
			break;
		}

		if (minusValid)
		{
			result2 = to_string(n - i).length() + i;
			break;
		}
	}

	cout << min(result1, result2);
}