#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
int num[20];
int currentSum = 0;
int result=0;

void dfs(int currIndex);

int main()
{
	cin >> N >> S;

	for(int i=0;i<N;i++)
	{
		cin >> num[i];
	}

	dfs(0);
	cout << result;
}

void dfs(int currIndex)
{
	if (currIndex == N) //주어진 숫자를 벗어났을 경우
	{
		return;
		//cout << "인덱스 초과" << endl;
	}

	if (currentSum + num[currIndex] == S) //현재 총합 + 현재 숫자가 목표치일 경우 result +1
	{
		result++;
		//cout << "result++" << endl;
	}

	//현재 숫자를 더하지 않고 계속하기
	dfs(currIndex+1);

	//현재 숫자를 더하고 계속하기
	currentSum += num[currIndex];
	dfs(currIndex+1);
	
	//끝까지 탐색했다면 이전 단계로 돌아가면서 직전에 더했던 값을 빼기
	currentSum -= num[currIndex];
}