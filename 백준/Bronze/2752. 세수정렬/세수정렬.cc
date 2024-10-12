#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int A[3];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 3; i++) cin >> A[i];
	sort(A, A + 3);
	for (auto a : A) cout << a << " ";
}