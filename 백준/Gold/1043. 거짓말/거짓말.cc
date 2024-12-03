#include <iostream>
#include <queue>
#include <unordered_set>
#include <cstring>
#include <set>
using namespace std;

int N, M;
bool isKnowing[51];
bool visited[51];
vector<int> knowingPerson;
vector<set<int>> adjList;
vector<vector<int>> party;

void DFS(int curr)
{
	visited[curr] = true;

	isKnowing[curr] = true;

	for (auto next : adjList[curr])
	{
		if (!visited[next])
		{
			DFS(next);
		}
	}
}

signed main()
{
	memset(isKnowing, 0, sizeof(isKnowing));
	memset(visited, 0, sizeof(visited));
	
	cin >> N >> M;
	adjList.resize(N + 1);

	int knowingPersonCount;
	cin >> knowingPersonCount;
	knowingPerson.resize(knowingPersonCount);
	for (int i = 0; i < knowingPersonCount; i++)
	{
		cin >> knowingPerson[i];
	}
		
	party.resize(M);
	for (int i = 0; i < M; i++)
	{
		int count;
		cin>> count;

		int first; cin >> first;
		party[i].push_back(first);
		//cout << "OK";
		count--;
		while(count--)
		{
			int input; cin >> input;
			party[i].push_back(input);
			adjList[first].insert(input);
			adjList[input].insert(first);
		}
		
	}

	for (int i = 0; i < knowingPerson.size(); i++)
	{
		if (!visited[knowingPerson[i]])
		{
			DFS(knowingPerson[i]);
		}
	}

	//cout << endl;
	//for (int i = 1; i <= N; i++)
	//{
	//	cout << i << " : " << isKnowing[i] << endl;
	//}

	int ret = 0;
	for (int i = 0; i < party.size(); i++)
	{
		//cout << "party " << i << endl;
		bool canLie = true;
		for (auto it = party[i].begin(); it != party[i].end(); it++)
		{
			if (isKnowing[*it])
			{
				canLie = false;
				break;
			}
		}
		if(canLie)
			ret++;
		//else
		//	cout << "cant lie" << endl;
	}
	cout << ret;
}
