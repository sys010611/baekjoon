#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char> s;

	int N, K;
	cin >> N >> K;

	string number;
	cin >> number;
	
	// 각 숫자는, 내 앞에 있는 놈들중에 나보다 작은 놈이 없었으면 좋겠음
	int popCount = 0;
	for(int i=0;i<N;i++)
	{
		int curr = number[i];

		while(!s.empty() && s.top()-'0' < curr - '0' && popCount < K)
		{
			s.pop();
			popCount++;
		}

		s.push(curr);
	}

	while(popCount < K) // 할당량만큼 빼지 못했을 경우 마저 빼주기
	{
		s.pop();
		popCount++;
	}

	string result;
	while(!s.empty())
	{
		result.push_back(s.top());
		s.pop();
	}

	reverse(result.begin(), result.end());

	cout << result;
}