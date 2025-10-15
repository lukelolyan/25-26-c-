#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    set<pair<int, int>> visited;
    visited.insert({1, 1});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        int v = grid[r - 1][c - 1];
        if (r == R && c == C) {
            cout << "yes\n";
            return 0;
        }


        for (int i = 1; i * i <= v; ++i) {
            if (v % i == 0) {
                int r2 = i;
                int c2 = v / i;

 
                if (r2 <= R && c2 <= C && !visited.count({r2, c2})) {
                    visited.insert({r2, c2});
                    q.push({r2, c2});
                }

                if (c2 <= R && r2 <= C && !visited.count({c2, r2})) {
                    visited.insert({c2, r2});
                    q.push({c2, r2});
                }
            }
        }
    }

    cout << "no\n";
    return 0;
}
