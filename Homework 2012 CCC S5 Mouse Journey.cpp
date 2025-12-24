#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    int K;
    cin >> K;

    vector<vector<bool>> cat(R + 1, vector<bool>(C + 1, false));
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        cat[r][c] = true;
    }

    vector<vector<long long>> dp(R + 1, vector<long long>(C + 1, 0));
    dp[1][1] = 1;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (cat[i][j] || (i == 1 && j == 1)) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    cout << dp[R][C] << endl;
    return 0;
}
