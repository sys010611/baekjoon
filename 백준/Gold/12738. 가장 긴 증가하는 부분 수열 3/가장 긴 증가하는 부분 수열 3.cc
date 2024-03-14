#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N;
vector<int> A;

int result = -1;

int lastNumOnLength[1000001]; // 인덱스 i = 수열의 길이, 요소 : 수열의 마지막 수

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(lastNumOnLength, lastNumOnLength+1000001, 2000000000); //무한대로 초기화
	lastNumOnLength[0] = -2000000000; // 길이가 0인 수열의 마지막 수 : 무한소

	cin >> N;

	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		A.push_back(input);
	}

	for (int i = 0; i < A.size(); i++)
	{
		int currNum = A[i];
		//currNum이 붙어서 될 수 있는 최장길이 탐색
		int possibleLength = lower_bound(lastNumOnLength, lastNumOnLength+1000001, currNum) - lastNumOnLength;

		/*cout << "CurrNum: " << currNum << endl;
		cout << "possibleLength : " << possibleLength << endl;*/

		// 길이가 k인 수열의 마지막 숫자를 최대한 작게 유지.
		if(lastNumOnLength[possibleLength] > A[i])
			lastNumOnLength[possibleLength] = A[i];

		if (possibleLength > result)
			result = possibleLength;
	}

	cout << result;
}