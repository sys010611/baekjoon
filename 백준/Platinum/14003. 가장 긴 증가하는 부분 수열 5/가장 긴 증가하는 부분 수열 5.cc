#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <vector>
using namespace std;

int N;
vector<int> A;

int result = -1;

int lastNumOnLength[1000001]; // 인덱스 i = 수열의 길이, 요소 : 수열의 마지막 수
int arrToLis[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(lastNumOnLength, lastNumOnLength + 1000001, 2000000000); //무한대로 초기화
	fill(arrToLis, arrToLis + 1000001, -1); //
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
		int possibleLength = lower_bound(lastNumOnLength, lastNumOnLength + 1000001, currNum) - lastNumOnLength;

		/*cout << "CurrNum: " << currNum << endl;
		cout << "possibleLength : " << possibleLength << endl;*/

		// 길이가 k인 수열의 마지막 숫자를 최대한 작게 유지.
		if (lastNumOnLength[possibleLength] > A[i])
			lastNumOnLength[possibleLength] = A[i];

		if (possibleLength > result)
			result = possibleLength;

		arrToLis[i] = possibleLength; // A에서 i번째인 수는 LIS에서는 possibleLength번째에 있음.
	}

	cout << result << endl;

	deque<int> resultDeq;
	int currPos = result; // LIS의 마지막 부터 시작, 앞으로 역추적
	for (int i = A.size() - 1; i >= 0; i--)
	{
		//cout << "현재 숫자: " << A[i] << endl;
		//cout << "LIS에서의 위치 : " << arrToLis[i] << endl;
		if (arrToLis[i] == currPos) // LIS의 현재 자리에 들어갈 수 있는 숫자라면, 덱에 푸쉬
		{
			//cout << "들어갈 수 있음" << endl;
			resultDeq.push_front(A[i]);
			currPos--;
		}

		if(currPos <= 0) break;
	}

	for (auto it = resultDeq.begin(); it != resultDeq.end(); it++)
	{
		cout << *it << " ";
	}
}