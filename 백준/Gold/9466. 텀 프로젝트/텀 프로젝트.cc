#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<bool> visited;
vector<bool> finished;
vector<bool> isInCycle;
vector<int> adjNode;

bool DFS(int curr, int& cycleNode)
{
	visited[curr] = true;

	bool ret = false;
	
	int next = adjNode[curr];
	if (!visited[next])
	{
		ret = DFS(next, cycleNode);
		if (ret)
			isInCycle[curr] = true;

		if(cycleNode == curr)
			ret = false;
	}
	else
	{
		if (!finished[next])
		{
			// 사이클 발견
			ret = true;

			cycleNode = next;
			//cout << "cycleNode : " << cycleNode << endl;
			isInCycle[curr] = true;

			if (cycleNode == curr)
				ret = false;
		}
	}

	finished[curr] = true;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		adjNode.resize(n+1);
		for (int i = 1; i <= n; i++)
			cin >> adjNode[i];
		
		visited.resize(n + 1);
		fill(visited.begin(), visited.end(), false);
		finished.resize(n + 1);
		fill(finished.begin(), finished.end(), false);
		isInCycle.resize(n + 1);
		fill(isInCycle.begin(), isInCycle.end(), false);

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				int cycleNode = -1;
				DFS(i, cycleNode);
			}
		}

		int result = 0;
		for (int i = 1; i <= n; i++)
		{
			//cout << i << " : " << isInCycle[i] << endl;
			if (!isInCycle[i]) result++;
		}
			

		cout << result << endl;
	}
}