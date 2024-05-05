#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

const int MAX = 5000;

int fail[MAX];

void MakeFailArr(const string& S)
{
	fill(fail, fail + MAX, 0);

	int N = S.length();

	for (int i = 1, j = 0; i < N; i++)
	{
		while (j > 0 && S[i] != S[j])
		{
			j = fail[j - 1];
		}

		if (S[i] == S[j])
		{
			fail[i] = ++j;
		}
	}

	//for (int i = 0; i < N; i++) printf("fail[%d] : %d\n", i, fail[i]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque<char> deq;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		deq.push_back(str[i]);
	}

	int result = 0;
	while (!deq.empty())
	{
		string s;
		for(char c : deq)
			s.append(1,c);

		//cout << "s : " << s << endl;

		MakeFailArr(s);

		result = max(result, *max_element(fail, fail + MAX));

		deq.pop_front();
	}
	cout << result;
}