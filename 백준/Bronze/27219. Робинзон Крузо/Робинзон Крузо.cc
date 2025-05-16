#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <map>
using namespace std;


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int a = n / 5;
    int b = n % 5;
    while (a--)
        cout << 'V';
    while (b--)
        cout << 'I';
}
