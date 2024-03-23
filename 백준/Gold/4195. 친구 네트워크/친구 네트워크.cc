#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

int p[200000];
map<string, int> personNo;

int find(int node)
{
	if (p[node] < 0) //값이 음수라면 루트. 음수가 아니면 그걸 부모로 하는 것임.
		return node;
	else
		return p[node] = find(p[node]);
}
void merge(int a, int b) //merge 하되, 루트의 p 값에는 컴포넌트의 크기를 저장
{
	int rootA = find(a);
	int rootB = find(b);

	if (rootA != rootB)
	{
		int sizeA = p[rootA];
		int sizeB = p[rootB];

		p[rootB] = rootA; //B를 A에 붙이기
		p[rootA] = sizeA + sizeB; //A에 합쳐진 컴포넌트의 크기 저장
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		memset(p, -1, sizeof(p));

		int personCount = 0;

		int F;
		cin >> F;

		string a, b;
		for (int i = 0; i < F; i++)
		{
			cin >> a >> b;

			if (personNo.find(a) == personNo.end()) // not found
			{
				personNo.insert({a, personCount++});
				//cout << a << "inserted " << endl;
			}
			if (personNo.find(b) == personNo.end()) // not found
			{
				personNo.insert({ b, personCount++ });
				//cout << b << "inserted " << endl;
			}

			if (find(personNo[a]) != find(personNo[b])) // 다른 컴포넌트에 있다면
			{
				merge(personNo[a], personNo[b]);
			}

			cout << -p[find(personNo[a])] << "\n";
		}

		//for (auto it = personNo.begin(); it != personNo.end(); it++)
		//{
		//	cout << "name : " << it->first << endl;
		//	cout << "number : " << it->second << endl << endl;
		//}
	}
}

