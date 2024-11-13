#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <queue>
#include <cstring>
#include <deque>
using namespace std;

#define double long double

int N, M;
typedef pair<double,double> P;


int p[1001];

double GetDist(P a, P b)
{
	auto dist = sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
	//cout << dist << endl;
	return dist;
}

class Edge
{
public:
	int u, v;
	double cost;

	bool operator< (Edge a)
	{
		return cost < a.cost;
	}
};

deque<Edge> edges;

int find(int n)
{
	if (p[n] == -1)
	{
		return n;
	}
	else
	{
		return p[n] = find(p[n]);
	}
}

void merge(int rootA, int rootB)
{
	p[rootB] = rootA;
}

int main()
{
	cin >> N >> M;
	memset(p, -1, sizeof(p));
	vector<P> points(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> points[i].first >> points[i].second;
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{	
			double dist = GetDist(points[i], points[j]);
			
			Edge edge;
			edge.u = i;
			edge.v = j;
			edge.cost = dist;
			edges.push_back(edge);
		}
	}
	sort(edges.begin(), edges.end());

	//for (auto edge : edges)
	//{
	//	cout << edge.u << " " << edge.v << " " << edge.cost << endl;
	//}

	//for (auto item : p)
	//{
	//	cout << item << " ";
	//}
	//cout << endl;

	int edgeCount = 0;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;

		int rootA = find(a);
		int rootB = find(b);

		if (rootA != rootB)
		{
			merge(rootA, rootB);
			edgeCount++;
		}
	}

	double result = 0;

	while (edgeCount < N - 1)
	{
		Edge curr = edges.front();
		edges.pop_front();

		int a = curr.u;
		int b = curr.v;

		//cout << "a : " << a << endl;
		//cout << "b : " << b << endl;

		int rootA = find(a);
		int rootB = find(b);

		//cout << "root a : " << rootA << endl;
		//cout << "root b : " << rootB << endl;

		if (rootA == rootB)
		{
			//cout << "같은 집합" << endl;
			continue;
		}
			
		//cout << "간선 추가 " << endl;
		//cout << curr.u << " " << curr.v << " " << curr.cost << endl;
		
		merge(rootA, rootB);
		result += curr.cost;

		edgeCount++;
	}

	cout << fixed;
	cout.precision(2);
	cout << result;
}
