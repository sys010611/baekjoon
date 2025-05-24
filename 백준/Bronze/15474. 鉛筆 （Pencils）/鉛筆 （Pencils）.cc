#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <climits>
#include <map>
#include <unordered_map>
using namespace std;

int n, a, b, c, d;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a >> b >> c >> d;

    int countA = 0, countB = 0;
    int moneyA = 0;
    int moneyB = 0;

    while (countA < n)
    {
        moneyA += b;
        countA += a;
    }

    while (countB < n)
    {
        moneyB += d;
        countB += c;
    }

    //cout << moneyA << " " << moneyB << endl;

    cout << min(moneyA, moneyB);
}
