#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
char a[100][100];
char b[100][100];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> b[i][j];
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (a[i][j] == b[i][j])
				ret++;
	}

	cout << ret; return 0;
}
