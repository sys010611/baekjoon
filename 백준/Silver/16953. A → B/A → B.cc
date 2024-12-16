#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
using namespace std;

#define int long long
#define SIZE 1000000001

int a, b;

int BFS()
{
	queue<int> Q;
	
	Q.push(a);

	int level = 0;
	
	while (!Q.empty())
	{
		int qSize = Q.size();
		while (qSize--)
		{
			int curr = Q.front(); Q.pop();
			if (curr > b)
			{
				continue;
			}
			//cout << "curr : " << curr << endl;

			if (curr == b)
				return level;

			int next1 = curr * 2;
			if (next1 < SIZE)
			{
				Q.push(next1);
			}
			int next2 = curr * 10 + 1;
			if (next2 < SIZE)
			{
				Q.push(next2);
			}
		}
		level++;
	}

	return -1;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a >> b;

	int ret = BFS();
	if (ret == -1)
	{
		cout << ret;
	}
	else
	{
		cout << ret + 1;
	}
}
