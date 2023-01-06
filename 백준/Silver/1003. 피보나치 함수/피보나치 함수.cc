#include <iostream>
using namespace std;

int main()
{
    int dp[40][2]; //각 n에 해당하는 0, 1의 출력 수
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        
        for (int i = 2; i < n + 1; i++)
        {
            dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
            dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
        }

        cout << dp[n][0] << " " << dp[n][1] << "\n";
    }
}