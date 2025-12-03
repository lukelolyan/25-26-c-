#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R, C;
    cin >> N >> M >> R >> C;

    if (R == N && C < M) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    if (C == M && R < N) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<string> g(N, string(M, 'a'));

    vector<int> bad_rows;
    for (int i = R; i < N; i++) bad_rows.push_back(i);

    for (int r : bad_rows) {
        if (M >= 2) {
            g[r][0] = 'a';
            g[r][1] = 'b';
        }
    }

    vector<int> bad_cols;
    for (int j = C; j < M; j++) bad_cols.push_back(j);

    int chosen_bad_row = -1;
    if (!bad_rows.empty()) chosen_bad_row = bad_rows[0];

    for (int j : bad_cols) {
        if (chosen_bad_row != -1) {
            g[chosen_bad_row][j] = 'c';
        }
    }

    for (int i = 0; i < N; i++) cout << g[i] << "\n";
}
