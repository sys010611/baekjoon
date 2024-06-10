#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void PrintVaseVec(std::vector<int>& mergedVase)
{
	cout << "물병 병합 현황 : ";
	for (auto item : mergedVase)
	{
		cout << item << " ";
	}
	cout << endl;
}

int main()
{
	int N, K;

	cin >> N >> K;

	vector<int> mergedVase; //합친 결과들
	vector<int> powersOfTwo; //2의 제곱수들

	int curr = 1;
	while (curr <= N)
	{
		powersOfTwo.push_back(curr);
		curr *= 2;
	}

	while (N > 1)
	{
		int powerOfTwo = *(upper_bound(powersOfTwo.begin(), powersOfTwo.end(), N)-1);
		
		mergedVase.push_back(powerOfTwo);
		N -= powerOfTwo;
	}

	if(N == 1) mergedVase.push_back(1);

	//PrintVaseVec(mergedVase);

	int mustBuyVaseCount = 0;

	while (mergedVase.size() > K)
	{
		int a = *(mergedVase.end() - 1);
		int b = *(mergedVase.end() - 2);

		while (a != b)
		{
			//cout << "물병 " << a << "개 구입 " << endl;
			mustBuyVaseCount += a;
			a *= 2;
		}
		mergedVase.pop_back();
		mergedVase.pop_back();
		mergedVase.push_back(a * 2);

		//PrintVaseVec(mergedVase);
	}

	cout << mustBuyVaseCount;
}