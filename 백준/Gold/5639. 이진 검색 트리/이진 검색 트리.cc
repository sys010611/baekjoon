#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#include <numeric>
#include <cstring>
using namespace std;

class TreeNode
{
public:
	int key;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int k)
	{
		key = k;
		left = nullptr;
		right = nullptr;
	}

	void insert(int key)
	{
		if (key < this->key)
		{
			if (left != nullptr)
				left->insert(key);
			else
				left = new TreeNode(key);
		}
		else
		{
			if (right != nullptr)
				right->insert(key);
			else
				right = new TreeNode(key);
		}
	}

	void PostOrder()
	{
		if(left != nullptr)
			left->PostOrder();
		if (right != nullptr)
			right->PostOrder();
		cout << key << endl;
	}
};

signed main()
{
	int key; cin >> key;
	TreeNode* T = new TreeNode(key);

	while (cin >> key)
	{
		// test
		//if (key == -1)
		//	break;

		T->insert(key);
	}

	T->PostOrder();
}

