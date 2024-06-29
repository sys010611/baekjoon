#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10;

/// <summary>
/// 얜 노드
/// </summary>
class Trie
{
public:
	Trie* next[MAX]; // 다음 노드
	bool isEnd; // 여기서 끝나는 전화번호가 있는지
	bool hasChild; // 자식노드를 가지고 있는지

	Trie()
	{
		fill(next, next+10, nullptr);
		isEnd = false;
		hasChild = false;
	}

	void insert(const char* key)
	{
		if(*key == '\0') // 끝에 다다른 경우
			isEnd = true; // 새로 자식을 파지 않음. 나 자신을 끝으로 표시.
		else
		{
			int nextNode = *key - '0';

			if (!next[nextNode])
				next[nextNode] = new Trie();

			next[nextNode]->insert(key + 1);
			hasChild = true;
		}
	}

	bool isConsistent()
	{
		// 나 검사
		if(isEnd && hasChild)
			return false;
		
		// 내 자식들 검사
		for (int i = 0; i < MAX; i++)
		{
			if(next[i] && !next[i]->isConsistent())
				return false;
		}

		return true;
	}


	~Trie()
	{
		for (int i = 0; i < MAX; i++)
			if(next[i])
				delete next[i];
	}
};

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>> n;

		Trie* root = new Trie();

		for (int i = 0; i < n; i++)
		{
			string number;
			cin >> number;

			root->insert(&number[0]);
		}

		if (root->isConsistent())
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		delete root;
	}
}