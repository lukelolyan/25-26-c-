#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W, D;
    cin >> N >> W >> D;

    vector<vector<int>> rev(N + 1);
    for (int i = 0; i < W; i++) {
        int A, B;
        cin >> A >> B;
        rev[B].push_back(A);
    }

    vector<int> walkDist(N + 1, INF);
    queue<int> q;
    walkDist[N] = 0;
    q.push(N);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : rev[u]) {
            if (walkDist[v] == INF) {
                walkDist[v] = walkDist[u] + 1;
                q.push(v);
            }
        }
    }

    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int size = 1;
    while (size < N) size <<= 1;
    vector<int> seg(2 * size, INF);

    auto value = [&](int i) {
        if (walkDist[S[i]] >= INF) return INF;
        return i + walkDist[S[i]];
    };


    for (int i = 0; i < N; i++) {
        seg[size + i] = value(i);
    }
    for (int i = size - 1; i > 0; i--) {
        seg[i] = min(seg[2 * i], seg[2 * i + 1]);
    }

    auto update = [&](int pos) {
        int i = size + pos;
        seg[i] = value(pos);
        for (i >>= 1; i > 0; i >>= 1) {
            seg[i] = min(seg[2 * i], seg[2 * i + 1]);
        }
    };


    while (D--) {
        int x, y;
        cin >> x >> y;
        x--; y--; 

        swap(S[x], S[y]);
        update(x);
        update(y);

        cout << seg[1] << '\n';
    }

    return 0;
}
