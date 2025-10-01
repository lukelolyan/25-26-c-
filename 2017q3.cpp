#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    const int MAXL = 2000;
    vector<int> freq(MAXL + 1, 0);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    int bestFence = 0;   
    int numHeights = 0;  

    for (int h = 2; h <= 2 * MAXL; h++) {
        int boards = 0;

        for (int a = max(1, h - MAXL); a <= h / 2; a++) {
            int b = h - a;
            if (b > MAXL) continue;
            if (a == b) boards += freq[a] / 2;
            else boards += min(freq[a], freq[b]);
        }

        if (boards > bestFence) {
            bestFence = boards;
            numHeights = 1;
        } else if (boards == bestFence) {
            numHeights++;
        }
    }

    cout << bestFence << " " << numHeights << "\n";
    return 0;
}
