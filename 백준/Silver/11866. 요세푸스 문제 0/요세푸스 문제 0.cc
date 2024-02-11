#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;

	vector<int> v;

	for(int i=1;i<=n;i++)
		v.push_back(i);

	vector<int>::iterator it = v.begin();

	cout << "<";

	while (v.size() > 1)
	{
		for (int i = 0; i < k-1; i++)
		{
			it++;

			if (it == v.end())
			{
				it = v.begin();
			}
		}

		cout << *it << ", ";

		it = v.erase(it);
		if (it == v.end())
		{
			it = v.begin();
		}
	}

	cout << v.front() << ">";
}