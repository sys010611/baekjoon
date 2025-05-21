#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <climits>
#include <map>
#include <unordered_map>
using namespace std;

int A[25][25];
int h, w;

int result = INT_MAX;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> A[i][j];
        }
    }

    // row, col = 幹線道路
    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            // test
            int currResult = 0;

            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    int currDist = min(abs(i - row), abs(j - col));
                    //cout << "currDist : " << currDist << endl;
                    //cout << "A[i][j] : " << A[i][j] << endl;
                    //cout << "A[i][j] * currDist : " << A[i][j] * currDist << endl;
                    currResult += A[i][j] * currDist;
                }
            }
            //cout << "currResult : " << currResult << endl;
            result = min(result, currResult);
        }
    }

    cout << result;
}
