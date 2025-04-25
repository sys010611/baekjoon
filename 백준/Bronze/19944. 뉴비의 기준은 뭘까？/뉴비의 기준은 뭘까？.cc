#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if (m <= 2)
    {
        cout << "NEWBIE!";
    }
    else if (m <= n)
    {
        cout << "OLDBIE!";
    }
    else
    {
        cout << "TLE!";
    }
}
