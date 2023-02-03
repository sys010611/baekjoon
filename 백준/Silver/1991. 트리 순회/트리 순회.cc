#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

class Tree
{
public:
	int N; //노드의 개수
	map<char,char> parent; //각 노드의 부모노드
	map<char, char> lc; //각 노드의 왼쪽 자식노드
	map<char, char> rc; //각 노드의 오른쪽 자식노드

	Tree(int n) //생성자
	{
		N = n;
	}

	void setChildren(char p, char l, char r)
	{
		parent[l] = p;
		lc[p] = l;
		
		parent[r] = p;
		rc[p] = r;
	}

	void preorder(char root)
	{
		cout << root;
		if (lc[root] != '.')
			preorder(lc[root]);
		if (rc[root] != '.')
			preorder(rc[root]);
	}

	void inorder(char root)
	{
		if (lc[root] != '.')
			inorder(lc[root]);
		cout << root;
		if (rc[root] != '.')
			inorder(rc[root]);
	}

	void postorder(char root)
	{
		if (lc[root] != '.')
			postorder(lc[root]);
		if (rc[root] != '.')
			postorder(rc[root]);
		cout << root;
	}

	/*void print()
	{
		for (char ch = 'A'; ch < 'H'; ch++)
		{
			cout << "------ node " << ch << " ---------" << endl;
			cout << "parent: " << parent[ch] << endl;
			cout << "left child: " << lc[ch] << endl;
			cout << "right child: " << rc[ch] << endl;
		}
	}*/
};

int main()
{
	int n;
	cin >> n;
	Tree T(n);

	char p,l,r;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> l >> r;
		T.setChildren(p,l,r);
	}

	T.preorder('A');
	cout << endl;
	T.inorder('A');
	cout << endl;
	T.postorder('A');

	//T.print();
}