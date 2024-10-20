#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <assert.h>
#include <climits>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		int A[3];
		for (int i = 0; i < 3; i++)
			cin >> A[i];

		sort(A, A + 3);

		int a = A[0];
		int b = A[1];
		int c = A[2];

		if (a == 0 && b == 0 && c == 0)
		{
			return 0;
		}

		if (a * a + b * b == c * c)
		{
			cout << "right" << endl;
		}
		else
		{
			cout << "wrong" << endl;
		}
	}
}