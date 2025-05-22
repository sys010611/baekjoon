#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <climits>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int currCoin = 0;
    for(int i=1;;i++)
    {
        currCoin += a;
        if (i % 7 == 0)
            currCoin += b;

        if (currCoin >= c)
        {
            cout << i;
            return 0;
        }
    }
}
