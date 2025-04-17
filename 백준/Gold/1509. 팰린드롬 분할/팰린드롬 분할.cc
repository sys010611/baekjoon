#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // 팰린드롬 여부를 저장하는 2차원 배열
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

    // 모든 길이가 1인 문자열은 팰린드롬
    for (int i = 0; i < n; ++i) {
        isPalindrome[i][i] = true;
    }

    // 길이가 2인 문자열도 팰린드롬 체크
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            isPalindrome[i][i + 1] = true;
        }
    }

    // 길이가 3 이상인 문자열에 대해서 팰린드롬 여부 계산
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                isPalindrome[i][j] = true;
            }
        }
    }

    // DP 배열
    vector<int> dp(n, INT_MAX);

    // 처음부터 i까지 팰린드롬으로 분할한 최소 횟수 계산
    for (int i = 0; i < n; ++i) {
        if (isPalindrome[0][i]) {
            dp[i] = 0;  // 첫 번째부터 i까지가 팰린드롬이라면 분할 횟수는 0
        } else {
            for (int j = 0; j < i; ++j) {
                if (isPalindrome[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }

    // 출력: 최솟값 + 1 (dp[i]는 부분 문자열의 개수를 세므로)
    cout << dp[n - 1] + 1 << endl;

    return 0;
}
