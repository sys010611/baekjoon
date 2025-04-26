#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    int appendCount = b.length() - a.length();

    for (int i = 0; i < appendCount; i++)
    {
        a.insert(0, "-");
        a.push_back('-');
    }
    //cout << "appendCount : " << appendCount << endl;
    //cout << a << endl;

    int ret = 1000000;

    for (int i = 0; i < a.length() - (b.length() - 1); i++)
    {
        int diff = 0;
        for (int j = 0; j < b.length(); j++)
        {
            char charA = a[i + j];
            char charB = b[j];

            if (charA != '-' && charA != charB)
            {
                diff++;
            }
        }

        //cout << "시작점 : " << i << endl;
        //cout << "diff : " << diff << endl;

        ret = min(ret, diff);
    }

    cout << ret;
}
