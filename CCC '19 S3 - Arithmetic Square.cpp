#include <bits/stdc++.h>
using namespace std;

bool isNum(string s) {
    return s != "X";
}

int main() {
    vector<vector<string>> grid(3, vector<string>(3));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> grid[i][j];

    vector<vector<long long>> a(3, vector<long long>(3, LLONG_MIN));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (isNum(grid[i][j])) a[i][j] = stoll(grid[i][j]);

    auto fillRow = [&](int i) {
        if (a[i][0] != LLONG_MIN && a[i][1] != LLONG_MIN && a[i][2] == LLONG_MIN)
            a[i][2] = 2 * a[i][1] - a[i][0];
        if (a[i][0] != LLONG_MIN && a[i][1] == LLONG_MIN && a[i][2] != LLONG_MIN)
            a[i][1] = (a[i][0] + a[i][2]) / 2;
        if (a[i][0] == LLONG_MIN && a[i][1] != LLONG_MIN && a[i][2] != LLONG_MIN)
            a[i][0] = 2 * a[i][1] - a[i][2];
    };

    auto fillCol = [&](int j) {
        if (a[0][j] != LLONG_MIN && a[1][j] != LLONG_MIN && a[2][j] == LLONG_MIN)
            a[2][j] = 2 * a[1][j] - a[0][j];
        if (a[0][j] != LLONG_MIN && a[1][j] == LLONG_MIN && a[2][j] != LLONG_MIN)
            a[1][j] = (a[0][j] + a[2][j]) / 2;
        if (a[0][j] == LLONG_MIN && a[1][j] != LLONG_MIN && a[2][j] != LLONG_MIN)
            a[0][j] = 2 * a[1][j] - a[2][j];
    };


    for (int _ = 0; _ < 100; _++) {
        for (int i = 0; i < 3; i++) fillRow(i);
        for (int j = 0; j < 3; j++) fillCol(j);
    }


    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (a[i][j] == LLONG_MIN) a[i][j] = 0;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j) cout << " ";
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}
