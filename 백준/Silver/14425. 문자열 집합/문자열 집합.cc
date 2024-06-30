#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

int N, M;
unordered_set<string> S;

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin>>s;
		S.insert(s);
	}
	int result=0;
	for (int i = 0; i < M; i++)
	{
		string s;
		cin>>s;
		if (S.find(s) != S.end())
		{
			result++;
		}
	}
	cout<<result;
}