#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

int G, P;
vector<int> arr;
int p[100001];

int find(int n)
{
	if(p[n] == -1)
		return n;
	else
		return p[n]=find(p[n]);
}

//a를 b에 달아주기.
void merge(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);

	p[rootA] = rootB;
}

void PrintP()
{
	cout << endl;
	for (int i = 1; i <= G; i++)
	{
		cout << i << "번 게이트의 부모 : " << p[i] << endl;
		cout << i << "번 게이트의 루트 : " << find(i) << endl;
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(p, -1, sizeof(p));

	cin >> G >> P;
	for (int i = 0; i < P; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}

	int result = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		//PrintP();

		int g = arr[i]; // 1~g까지 게이트 중 하나에 도킹해야함.

		int gate = find(g); //루트 게이트를 찾기

		if (gate == 0) // 0번 게이트는 없는 게이트임. 0까지 갔다 = 비행기를 도킹할 수 없다.
		{
			break;
		}
		else
		{
			result++;
			merge(gate, gate-1); // gate에 도킹 완료. 이제 gate로 요청 들어오면 그 전 게이트로 들어가야함.

			//cout << g << "에의 요청 " << gate << "으로 도킹 완료" << endl;
		}
	}
	cout << result;
}

