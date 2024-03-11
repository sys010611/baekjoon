#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main()
{
	int n;

	cin >> n;

	vector<int> v;

	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v.push_back(input);
	}

	int prevNum = -1;
	long long increasingCount = 0;

	long long result = 0;

	for (int i = 0; i < n; i++)
	{
		//cout << v[i] << endl;
		if (v[i] > prevNum)
		{
			//cout << "증가" << endl;
			increasingCount++;
		}
		else
		{
			//cout << "증가 멈춤" << endl;
			//cout << "increasingCount: " << increasingCount << endl;

			if (increasingCount == 1)
			{
				result += 1;
			}
			else
			{
				long long count = (increasingCount * (increasingCount + 1)) / 2;
				result += count;
			}

			increasingCount = 1;
		}
		prevNum = v[i];

		//cout << "result: " << result << endl;
	}
	if (increasingCount == 0)
	{
		result += 1;
	}
	else
	{
		long long count = (increasingCount * (increasingCount + 1)) / 2;
		result += count;
	}

	cout << result;
}