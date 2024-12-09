#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;


signed main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int bDivA = b / a;

	cout << c * 3 * bDivA;
}
