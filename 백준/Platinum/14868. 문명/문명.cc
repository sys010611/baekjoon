#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

const int MAX = 2001;
int N, K;
int parent[MAX * MAX]; // DSU
int board[MAX][MAX];   // 문명 ID 저장
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}

int idx(int x, int y) {
    return (x - 1) * N + y; // 고유 번호로 변환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    queue<pair<int, int>> q;
    queue<tuple<int, int, int>> nxt; // (x, y, 문명id)

    int total_unions = K;
    for (int i = 1; i <= K; ++i) {
        int x, y;
        cin >> x >> y;
        board[x][y] = i;
        q.push({x, y});
        parent[i] = i;
    }

    // 초기 인접 문명 결합
    queue<pair<int, int>> temp = q;
    while (!temp.empty()) {
        auto [x, y] = temp.front(); temp.pop();
        int civ = board[x][y];
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if (board[nx][ny]) {
                if (merge(civ, board[nx][ny])) total_unions--;
            }
        }
    }

    int year = 0;
    while (total_unions > 1) {
        // 확산 단계
        int sz = q.size();
        while (sz--) {
            auto [x, y] = q.front(); q.pop();
            int civ = board[x][y];
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
                if (board[nx][ny] == 0) {
                    board[nx][ny] = civ;
                    nxt.push({nx, ny, civ});
                }
            }
        }

        // 결합 단계
        while (!nxt.empty()) {
            auto [x, y, civ] = nxt.front(); nxt.pop();
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
                if (board[nx][ny] && board[nx][ny] != civ) {
                    if (merge(board[nx][ny], civ)) total_unions--;
                }
            }
            q.push({x, y});
        }

        year++;
    }

    cout << year << '\n';
    return 0;
}
