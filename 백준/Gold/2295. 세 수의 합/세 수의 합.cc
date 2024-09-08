#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define int long long

int N;
vector<int> U;
vector<int> sumOfTwo;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	U.resize(N);
	for(int i=0;i<N;i++)
		cin >> U[i];
	sort(U.begin(), U.end());

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sumOfTwo.push_back(U[i] + U[j]);
		}
	}
	sort(sumOfTwo.begin(), sumOfTwo.end());

	//for(auto item : U)
	//	cout << item << " ";
	//cout << endl;
	//for (auto item : sumOfTwo)
	//	cout << item << " ";
	//cout << endl;

	for (int i = N - 1; i > -1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			int dMinusC = U[i] - U[j];

			auto lb = lower_bound(sumOfTwo.begin(), sumOfTwo.end(), dMinusC);
			if (lb != sumOfTwo.end() && *lb == dMinusC)
			{
				//found
				cout << U[i];
				return 0;
			}
		}
	}
}