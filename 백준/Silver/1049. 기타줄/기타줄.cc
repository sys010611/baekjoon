#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	cin >> n >> m;

	int* package = new int[m];
	int* single = new int[m];

	for (int i = 0; i < m; i++)
	{
		cin >> package[i] >> single[i];
	}

	sort(package, package+m);
	sort(single, single+m);

	if (package[0] >= 6 * single[0]) //묶음보다 낱개가 더 싼 경우
	{
		cout << single[0] * n;
		return 0;
	}

	if (n % 6 != 0) // 애매하게 남을 경우
	{
		if (n % 6 * single[0] < package[0]) //나머지를 낱개로 사는게 더 싼 경우
		{
			cout << n / 6 * package[0] + n % 6 * single[0];
			return 0;
		}
		else //그렇지 않으면 패키지 하나 더 사기
		{
			cout << (n / 6 + 1) * package[0];
			return 0;
		}
	}
	else
	{
		cout << n/6 * package[0];
	}
}