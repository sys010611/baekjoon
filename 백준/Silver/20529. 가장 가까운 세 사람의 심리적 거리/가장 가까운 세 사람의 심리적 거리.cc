#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int Calculate(const vector<string>& strings)
{
	string A = strings[0];
	string B = strings[1];
	string C = strings[2];

	int hammingDistance = 0;

	for (int i = 0; i < 4; i++)
	{
		if (A[i] != B[i])
			hammingDistance++;
		if (B[i] != C[i])
			hammingDistance++;
		if (C[i] != A[i])
			hammingDistance++;
	}

	return hammingDistance;
}

int main()
{
	int t;
	cin >> t;
	while (t--) // test case
	{
		int minResult = 1000000000;

		vector<string> v; // mbti를 담을 벡터

		int N;
		cin >> N;

		string input; // 입력할 mbti
		vector<int> selector; // 0 , 1을 담을 벡터

		for (int i = 0; i < N; i++)
		{
			cin >> input;
			v.push_back(input);
		}

		if (N >= 33) // 33명 이상일 경우 무조건 3명이 MBTI가 겹침
		{
			cout << 0 << endl;
			continue;
		}

		for (int i = 0; i < N; i++)
		{
			if (i < 3)
				selector.push_back(0);
			else
				selector.push_back(1);
		}

		sort(selector.begin(), selector.end());

		do
		{
			vector<string> testList;
			for (int i = 0; i < selector.size(); i++)
			{
				if (selector[i] == 0)
				{
					testList.push_back(v[i]);
				}
			}

			int result = Calculate(testList);

			if (result < minResult)
			{
				minResult = result;
			}
		} while (next_permutation(selector.begin(), selector.end()));

		cout << minResult << endl;
	}
}