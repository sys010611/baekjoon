#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;




int dRow[8] = { 0,-1,-1,-1,0,1,1,1 };
int dCol[8] = { 1,1,0,-1,-1,-1,0,1 };

char grid[4][4];
bool visited[4][4];

class Trie
{
public:
	Trie* child[26];

	Trie()
	{
		for (int i = 0; i < 26; i++)
		{
			child[i] = nullptr;
		}
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++)
		{
			if (child[i])
				delete(child[i]);
		}
	}

	Trie* insert(const char key)
	{
		int next = key - 'A';

		if (!child[next])
			child[next] = new Trie();

		return child[next];
	}

	bool find(const char* key)
	{
		if (*key == '\0')
			return true;

		int next = *key - 'A';

		if (!child[next])
			return false;
		else
			return true && child[next]->find(key + 1);
	}
};

struct Compare
{
	bool operator() (const string& a, const string& b) const
	{
		if (a.length() != b.length())
		{
			return a.length() > b.length();
		}
		else
		{
			return a < b;
		}
	}
};

vector<string> words;
set<string, Compare> answer;

void make_trie(Trie* curr, int row, int col, int depth)
{
	if(depth > 8)
		return;

	Trie* next = curr->insert(grid[row][col]);

	visited[row][col] = true;

	for (int i = 0; i < 8; i++)
	{
		int nRow = row + dRow[i];
		int nCol = col + dCol[i];

		if (nRow < 0 || nRow >= 4 || nCol < 0 || nCol >= 4 || visited[nRow][nCol])
			continue;
		else
			make_trie(next, nRow, nCol, depth+1);
	}
	visited[row][col] = false;
}

void find_words(Trie* root)
{
	for (string str : words)
	{
		if (root->find(&str[0]))
		{
			answer.insert(str);
		}
	}
	return;
}



int calcScore()
{
	int score = 0;
	for (auto& item : answer)
	{
		int length = item.length();
		if (length <= 2) score += 0;
		else if (length <= 4) score += 1;
		else if (length <= 5) score += 2;
		else if (length <= 6) score += 3;
		else if (length <= 7) score += 5;
		else if (length <= 8) score += 11;
	}
	return score;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int w;
	cin >> w;
	for (int i = 0; i < w; i++)
	{
		string str;
		cin >> str;
		words.push_back(str);
	}

	int b;
	cin >> b;
	for (int i = 0; i < b; i++)
	{
		answer.clear();

		fill(&visited[0][0], &visited[3][4], false);

		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				cin >> grid[row][col];
			}
		}


		// 백트래킹 식으로 트라이 구축
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				Trie* root = new Trie();
				make_trie(root, row, col, 1);

				find_words(root);
				delete(root);

			}
		}
		//for(auto item : answer) cout << item << endl;

		cout << calcScore() << " " << *answer.begin() << " " << answer.size() << '\n';

	}
}