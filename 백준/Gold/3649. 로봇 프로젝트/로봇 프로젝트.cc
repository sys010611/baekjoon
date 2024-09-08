#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define int long long

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, n;
	while (true)
	{
		cin >> x >> n;
		if(cin.eof())
			break;

		x *= 10000000;

		vector<int> legos;
		legos.resize(n);

		for(int i=0;i<n;i++)
			cin >> legos[i];

		if (n < 2)
		{
			cout << "danger" << endl;
			continue;
		}

		sort(legos.begin(), legos.end());

		//for(auto item : legos)
		//	cout << item << " ";
		//cout << endl;

		bool success = false;
		for (int i = 0; i < n; i++)
		{
			int pivot = legos[i];
			//cout << "pivot : "<< pivot << endl;
			int target = x - pivot;
			//cout << "target : " << target << endl;

			auto lb = lower_bound(legos.begin(), legos.end(), target);

			if (lb - legos.begin() == i) // 같은 막대기를 두번 쓰지 않도록
				lb++;

			if (lb != legos.end() && *lb == target)
			{
				success = true;
				cout << "yes " << pivot << " " << target << endl;
				break;
			}
		}

		if(!success)
			cout << "danger" << endl;
	}
	return 0;
}