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

    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
    // how many 1 is continuous?
    int count = 0;
    int result = -1;
    for (auto item : v)
    {
        if (item == 1)
            count++;
        else
            count = 0;

        result = max(result, count);
    }

    cout << result + 1;
}
