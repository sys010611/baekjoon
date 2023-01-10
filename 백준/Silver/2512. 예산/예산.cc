#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	long long M;
	int maxBudget; //상한액
	long long maxBudgetTest = 0;

	cin >> N;
	int* provinces = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> provinces[i];
	}
	cin >> M;

	//상한액이 의미가 없을 경우 (다 줘도 상관이 없을 경우)
	for (int i = 0; i < N; i++)
	{
		maxBudgetTest += provinces[i];
	}
	if (maxBudgetTest <= M)
	{
		int answer = *max_element(provinces, provinces + N);
		cout << answer;
		return 0;
	}

	int min = 0;
	int max = 100000;

	while (max - min > 1)
	{
		//cout << "max: " << max << endl;
		//cout << "min: " << min << endl;

		long long sum = 0;
		maxBudget = (max + min) / 2; //상한액 = 중간값

		for (int i = 0; i < N; i++)
		{
			if (provinces[i] > maxBudget)
			{
				sum += maxBudget;
			}
			else
			{
				sum += provinces[i];
			}
		}

		//cout << "계산 결과: " << sum << endl;
		//cout << "총 예산: " << M << endl;

		if (sum < M)
		{
			min = maxBudget;
		}
		else if (sum > M)
		{
			max = maxBudget;
		}
		else
		{
			//cout << "맞아 떨어짐" << endl;
			cout << maxBudget;
			return 0;
		}
	}

	//cout << "맞아 떨어지지 않음" << endl;
	cout << min;
}