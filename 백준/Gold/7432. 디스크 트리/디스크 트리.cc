#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class Trie
{
public:
	map<string, Trie*> child;
	Trie()
	{

	}
	~Trie()
	{
		for(auto& item : child)
			delete(item.second);
	}

	// 자식 노드의 주소를 반환
	Trie* insert(const string& key)
	{
		if (child.find(key) == child.end())
		{
			child[key] = new Trie();
		}
		return child[key];
	}

	void print(int depth)
	{
		for (auto& c : child)
		{
			for(int i=0;i<depth;i++)
				cout << ' ';

			cout << c.first << endl;

			c.second->print(depth+1);
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Trie* root = new Trie();
	Trie* curr;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		curr = root;

		string dir;
		cin >> dir;

		istringstream ss(dir);
		string folder;

		while (getline(ss, folder, '\\'))
		{
			curr = curr->insert(folder);
		}
	}

	// 출력
	root->print(0);
}