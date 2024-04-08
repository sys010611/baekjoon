#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> P;

int segTree[2000000]; //y축 상 각 위치의 점의 유무를 담음

bool compare(P a, P b)
{
	if(a.first == b.first)
		return a.second > b.second;
	else
		return a.first < b.first;
}

bool compareByY(P a, P b)
{
	return a.second < b.second;
}

void PrintTree(int treeN)
{
	for (int i = 1; i < 2 * treeN; i++)
	{
		cout << "segtree " << i << " : " << segTree[i] << endl;
	}
}

void Construct(int node)
{
	node /= 2;
	while (node > 0)
	{
		segTree[node] = segTree[node*2] + segTree[node*2 + 1];
		node /= 2;
	}
}

int GetSum(int L, int R, int nodeNo, int nodeL, int nodeR)
{
	if (L <= nodeL && nodeR <= R) // 완전히 포함
	{
		//cout << " 완전히 포함" << endl;
		return segTree[nodeNo];
	}

	if (R < nodeL || L > nodeR) // 완전히 빗나감
	{
		//cout << " 완전히 빗나감" << endl;
		return 0;
	}

	//일부만 포함
	//cout << " 일부만 포함" << endl;
	int mid = (nodeL + nodeR)/2;
	return GetSum(L, R, nodeNo*2, nodeL, mid) + GetSum(L,R,nodeNo*2+1, mid+1, nodeR);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		long long result = 0;
		memset(segTree, 0, sizeof(segTree));

		int n;
		cin >> n;

		int treeN = 1; // 리프 노드의 개수
		while(treeN < n)
			treeN *= 2;

		vector<pair<int,int>> vec;
		
		for (int i = 0; i < n; i++)
		{
			int x,y;
			cin >> x >> y;
			vec.push_back(make_pair(x,y));
		}

		sort(vec.begin(), vec.end(), compareByY); // y값 기준 오름차순 정렬

		// y축 좌표압축
		int lastY = vec[0].second;
		vec[0].second = 0;
		int replacedValueY = vec[0].second;
		for (auto it = vec.begin() + 1; it != vec.end(); it++)
		{
			if(it->second == lastY)
				it->second = replacedValueY;
			else
			{
				lastY = it->second;
				it->second = ++replacedValueY;
			}
		}
		

		sort(vec.begin(), vec.end(), compare); // x축 기준 오름차순, 그 안에서는 y축 기준 내림차순 정렬

		for (int i = 0; i < vec.size(); i++)
		{
			int x = vec[i].first;
			int y = vec[i].second;

			//cout << "x : " << x << ", y : " << y << endl;

			/*순회를 하면서, 지금 세그먼트 트리에 들어있는 것들은 나보다 왼쪽에 있었던 것들임
			따라서 트리에 들어있는 것 중 나보다 위에있는 것을 세면 그 점들의 개수가 나한테 항해해올 수 있는 섬의 개수*/
			
			//PrintTree(treeN);

			result += GetSum(y, treeN-1, 1, 0, treeN-1);
			//cout << "result : " << result << endl;

			// 세그먼트 트리에 현재 섬 추가
			segTree[treeN + y] += 1;

			Construct(treeN + y);
		}

		cout << result << endl;
	}
}


