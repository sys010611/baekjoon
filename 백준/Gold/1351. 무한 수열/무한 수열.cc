#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<long long, long long> m;
long long N, P, Q;

long long calculate(long long n)
{
	if (m.count(n))
		return m[n];
	else
		return m[n] = calculate(n/ P) + calculate(n/ Q);
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> P >> Q;
	m[0] = 1;

	cout << calculate(N);
}