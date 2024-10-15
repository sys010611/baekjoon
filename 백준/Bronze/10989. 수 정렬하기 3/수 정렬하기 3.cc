#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;
int counts[10001];
//vector<int> sorted;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(counts, counts+10001, 0);
	
	cin >> N;
	//sorted.resize(N);

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		counts[input]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		if (counts[i] > 0)
		{
			for(int j=0;j<counts[i];j++)
			{
				cout << i << '\n';
			}
		}
	}
}
