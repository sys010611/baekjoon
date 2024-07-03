#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<string, int> nameCount;

class Trie
{
public:
	Trie* child[26];
	
	Trie()
	{
		for(int i=0;i<26;i++)
			child[i] = nullptr;
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++)
			if(child[i])
				delete(child[i]);
	}

	char* insert(char* key, char* charptr, bool gotResult)
	{
		if (*key == '\0')
			return charptr;

		int next = *key - 'a';

		// 노드를 처음 새로 만드는 타이밍이 곧 별칭이 정해지는 시기
		if (!child[next])
		{
			child[next] = new Trie();
			if (!gotResult)
			{
				charptr = key;
				gotResult = true;
			}
		}

		return child[next]->insert(key+1, charptr, gotResult);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Trie* root = new Trie();


	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;

		if (nameCount.find(name) == nameCount.end())
		{
			nameCount[name] = 1;

			char* endPoint = root->insert(&name[0], nullptr, false);

			if (endPoint == nullptr)
			{
				cout << name << '\n';
				continue;
			}

			int endIdx = endPoint - &name[0];

			for (int i = 0; i <= endIdx; i++)
				cout << name[i];
			cout << '\n';
		}
		else
		{
			nameCount[name]++;
			cout << name << nameCount[name] << '\n';
		}

	}
}