#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> h(N);
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    vector<int> ans(N + 1, 1e9 + 7);

    for (int i = 0; i < N; ++i) {
        int l = i;
        int r = i;
        int current_asymmetry = 0;

        while (l >= 0 && r < N) {
            if (l != r) { 
                current_asymmetry += abs(h[l] - h[r]);
            }
            int len = r - l + 1;
            if (current_asymmetry < ans[len]) {
                ans[len] = current_asymmetry;
            }
            l--;
            r++;
        }
    }

    for (int i = 0; i < N - 1; ++i) {
        int l = i;
        int r = i + 1;
        int current_asymmetry = 0;

        while (l >= 0 && r < N) {
            current_asymmetry += abs(h[l] - h[r]);
            int len = r - l + 1;
            if (current_asymmetry < ans[len]) {
                ans[len] = current_asymmetry;
            }
            l--;
            r++;
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << (i == N ? "" : " ");
    }
    cout << endl;

    return 0;
}
