#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <climits>
#include <map>
#include <unordered_map>
using namespace std;

deque<int> cards;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= 2*n; i++)
    {
        cards.push_back(i);
    }

    int m;
    cin >> m;
    while (m--)
    {
        int k;
        cin >> k;
        if (k != 0)
        {
            // 整数 k でカット

            deque<int> a, b;


            for (int i = 0; i < k; i++)
            {
                a.push_back(cards[0]);
                cards.pop_front();
            }
            while(!cards.empty())
            {
                b.push_back(cards[0]);
                cards.pop_front();
            }

            for (auto item : b)
            {
                cards.push_back(item);
            }
            for (auto item : a)
            {
                cards.push_back(item);
            }

            //cout << " 整数 k でカット" << endl;
            //// debug
            //for (auto item : cards)
            //    cout << item << endl;
        }
        else
        {
            // リフルシャッフル
            deque<int> a, b;
            for (int i = 0; i < n; i++)
            {
                a.push_back(cards[0]);
                cards.pop_front();
            }
            for (int i = 0; i < n; i++)
            {
                b.push_back(cards[0]);
                cards.pop_front();
            }

            for (int i = 0; i < n; i++)
            {
                cards.push_back(a[i]);
                cards.push_back(b[i]);
            }

            // debug
            //cout << " リフルシャッフル" << endl;
            //for (auto item : cards)
            //    cout << item << endl;
        }
    }

    for (auto item : cards)
        cout << item << endl;
}
