#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 2000000000;
typedef pair<int,int> P;

int N;

vector<int> plusVec;
vector<int> minusVec;
P currPair(-1, -1);
int currResult = INF;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		if (input < 0)
			minusVec.push_back(input);
		else if (input > 0)
			plusVec.push_back(input);
	}

	sort(minusVec.begin(), minusVec.end());
	sort(plusVec.begin(), plusVec.end());

	if (minusVec.size() > 0 && plusVec.size() > 0)
	{
		for (int i = 0; i < minusVec.size(); i++) // 산성 알칼리 섞는 경우 검사
		{
			int minusVal = minusVec[i];
			//cout << "minusVal: " << minusVal << endl;

			int plusVecIdx = lower_bound(plusVec.begin(), plusVec.end(), -minusVal) - plusVec.begin();

			plusVecIdx = min(plusVecIdx, (int)(plusVec.size()-1));

			if (abs(plusVec[plusVecIdx] + minusVal) < currResult)
			{
				currPair = P(minusVal, plusVec[plusVecIdx]);
				currResult = abs(plusVec[plusVecIdx] + minusVal);
			}
			if (plusVecIdx - 1 >= 0 && abs(plusVec[plusVecIdx - 1] + minusVal) < currResult)
			{
				currPair = P(minusVal, plusVec[plusVecIdx - 1]);
				currResult = abs(plusVec[plusVecIdx - 1] + minusVal);
			}
		}
	}
	
	//산성끼리, 알칼리끼리 검사
	if (minusVec.size() >= 2)
	{
		int m1 = minusVec[minusVec.size() - 2];
		int m2 = minusVec[minusVec.size() - 1];
		int minBetweenMinus = -(m1 + m2);
		if (minBetweenMinus < currResult)
		{
			currPair = P(m1, m2);
			currResult = minBetweenMinus;
		}
	}
	if (plusVec.size() >= 2)
	{
		int p1 = plusVec[0];
		int p2 = plusVec[1];
		int minBetweenPlus = p1+p2;
		if (minBetweenPlus < currResult)
		{
			currPair = P(p1,p2);
			currResult = minBetweenPlus;
		}
	}

	
	//cout << "currResult: " << currResult << endl;
	//cout << "currPair: " << currPair.first << ", " << currPair.second << endl;
	cout << currPair.first << " " << currPair.second;
}