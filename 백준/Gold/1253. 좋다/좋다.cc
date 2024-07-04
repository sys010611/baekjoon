#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long

int N;
vector<int> arr;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int result = 0;

	for (int i = 0; i < N; i++)
	{
		int target = arr[i];
		int S = 0;
		int E = N-1;

		if (S == i)
			S++;
		if (E == i)
			E--;

		while (S < E)
		{	
			int sum = arr[S] + arr[E];
			if (sum > target)
			{
				E--;
				if(E == i)
					E--;
			}
			else if (sum < target)
			{
				S++;
				if(S == i)
					S++;
			}
			else //sum == target
			{
				result++;
				break;
			}
		}
		
	}

	cout << result;
}