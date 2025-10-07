#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    auto is_valid = [&](const vector<vector<int>>& m) {

        for (int i = 0; i < n; ++i)
            for (int j = 1; j < n; ++j)
                if (m[i][j] <= m[i][j-1]) return false;

        for (int j = 0; j < n; ++j)
            for (int i = 1; i < n; ++i)
                if (m[i][j] <= m[i-1][j]) return false;
        return true;
    };

    auto rotate90 = [&](const vector<vector<int>>& m) {
        vector<vector<int>> r(n, vector<int>(n));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                r[i][j] = m[n-1-j][i];
        return r;
    };

    for (int k = 0; k < 4; ++k) {
        if (is_valid(a)) break;
        a = rotate90(a);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << '\n';
    }
    return 0;
}
