#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <map>
#include <unordered_map>
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    int time = x + y;
    if ((float)time <= (float)z + 0.5)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}
