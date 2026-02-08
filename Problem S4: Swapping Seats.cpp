#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solve(int n, const string& s, const vector<vector<int>>& pref, char x, char y, char z, int countX, int countY, int countZ) {
    int min_swaps = 1e9;
    for (int i = 0; i < n; ++i) {
        
        auto get_count = [&](char c, int l, int r) {
            int char_idx = c - 'A';
            return pref[char_idx][r + 1] - pref[char_idx][l];
        };
        int y_in_X = get_count(y, i, i + countX - 1);
        int z_in_X = get_count(z, i, i + countX - 1);
        int x_in_Y = get_count(x, i + countX, i + countX + countY - 1);
        int z_in_Y = get_count(z, i + countX, i + countX + countY - 1);

        int direct_XY = min(y_in_X, x_in_Y);
        
        int total_wrong = (y_in_X + z_in_X) + (x_in_Y + z_in_Y);
        min_swaps = min(min_swaps, total_wrong - direct_XY);
    }
    return min_swaps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();
    
    int countA = 0, countB = 0, countC = 0;
    for (char c : s) {
        if (c == 'A') countA++;
        else if (c == 'B') countB++;
        else if (c == 'C') countC++;
    }

    string double_s = s + s;
    vector<vector<int>> pref(3, vector<int>(2 * n + 1, 0));
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 3; ++j) pref[j][i + 1] = pref[j][i];
        pref[double_s[i] - 'A'][i + 1]++;
    }

    int ans = 1e9;
    ans = min(ans, solve(n, double_s, pref, 'A', 'B', 'C', countA, countB, countC));
    ans = min(ans, solve(n, double_s, pref, 'A', 'C', 'B', countA, countC, countB));
    ans = min(ans, solve(n, double_s, pref, 'B', 'A', 'C', countB, countA, countC));
    ans = min(ans, solve(n, double_s, pref, 'B', 'C', 'A', countB, countC, countA));
    ans = min(ans, solve(n, double_s, pref, 'C', 'A', 'B', countC, countA, countB));
    ans = min(ans, solve(n, double_s, pref, 'C', 'B', 'A', countC, countB, countA));

    cout << ans << endl;

    return 0;
}
