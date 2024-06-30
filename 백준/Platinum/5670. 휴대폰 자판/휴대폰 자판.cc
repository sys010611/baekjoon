#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 26;

class Trie
{
	Trie* child[MAX];
	bool isOutput;
	bool hasChild;

public:
	Trie()
	{
		isOutput = false;
		hasChild = false;
		for (int i = 0; i < MAX; i++)
			child[i] = nullptr;
	}
	~Trie()
	{
		for(int i=0;i<MAX;i++)
			if(child[i]) delete(child[i]);
	}
	void insert(char* key)
	{
		if (*key == '\0')
			this->isOutput = true;
		else
		{
			int next = *key - 'a';
			if(!child[next])
				child[next] = new Trie();

			child[next]->insert(key+1);
			this->hasChild = true;
		}
	}

	int getCount(char* key, bool isFirst)
	{
		int count = 0;

		// 끝까지 왔을 경우 바로 리턴
		if (*key == '\0')
			return count;

		// 첫 글자는 무조건 입력 필요
		if (isFirst)
		{
			count++;
		}
		else
		{
			// 분기가 있을 경우 입력 필요
			int childCount = 0;
			for (int i = 0; i < MAX; i++)
			{
				if (child[i])
					childCount++;
			}
			if (childCount >= 2)
				count++;
			else
			{
				// 중간에 output node를 만났을 경우 입력 필요
				if (isOutput)
					count++;
			}
		}

		int next = *key - 'a';
		return count + child[next]->getCount(key+1, false);
	}
};

int main()
{
	std::cout<<fixed;
	std::cout.precision(2);

	while (true)
	{
		int N;
		if(scanf("%d", &N) == EOF) return 0;

		vector<string> strings;

		Trie* root = new Trie();

		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			strings.push_back(s);

			root->insert(&s[0]);
		}

		vector<int> counts;

		for (int i = 0; i < N; i++)
		{
			string s = strings[i];
			//cout << "string: " << s << endl;
			//cout << "필요한 횟수 : " << (root->getCount(&s[0], true)) << endl;
			counts.push_back(root->getCount(&s[0], true));
		}

		// 이제 counts의 평균을 구하면 끝
		float sum=0;
		for(auto item: counts)
			sum += item;

		std::cout << sum / counts.size() << endl;

		delete root;
	}
}