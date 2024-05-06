#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;

bool compare(pair<char, int> a, pair<char, int> b)
{
	return a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<string> v;

	map<char, int> dic; //알파벳 대문자를 숫자로 바꿔주는 map
	vector<pair<char,int>> weights; //각 알파벳들이 얼마만큼의 비중을 가지고 있는지

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}

	for (int i = 0; i < 26; i++)
	{
		weights.push_back(make_pair('A'+i, 0));
	}

	for (auto str : v)
	{
		for (int i = 0; i < str.length(); i++)
		{
			char c = str[i];
			weights[c - 'A'].second += pow(10, str.length() - 1 - i);
		}
	}

	//for (int i=0;i<26;i++) cout << weights[i].first << " -> " << weights[i].second << endl;

	sort(weights.begin(), weights.end(), compare);

	//for (int i = 0; i < 26; i++) cout << weights[i].first << " -> " << weights[i].second << endl;

	int allocNum = 9;
	for (int i = 0; i < 26; i++)
	{
		if(weights[i].second == 0)
			break;

		if(dic.find(weights[i].first) == dic.end())
			dic[weights[i].first] = allocNum--;
	}

	//for (auto pair : dic)	cout << pair.first << " -> " << pair.second << endl;

	int result = 0;
	for (string s : v)
	{
		while (!s.empty())
		{
			result += dic[s[0]] * pow(10, s.length()-1);
			s.erase(0,1);
		}
	}

	cout << result;
}