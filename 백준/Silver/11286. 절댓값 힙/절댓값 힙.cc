#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct cmp
{
	bool operator()(int a, int b) //절댓값이 가장 작은 것이 top (같다면 음수가 top)
	{
		if (abs(a) == abs(b))
		{
			if (b<0 && a>0)
				return true; //b가 음수라면 swap (우선순위 올라감)
			else
				return false;
		}
		else if (abs(a) > abs(b))
			return true; //b의 절댓값이 더 작다면 swap
		else
			return false;
	}
};

priority_queue<int, vector<int>, cmp> Q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		
		if (x == 0)
		{
			if (Q.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << Q.top() << "\n";
				Q.pop();
			}
		}
		else
		{
			Q.push(x);
		}
	}
}