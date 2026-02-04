#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> p(N), w(N), d(N);

    long long L = LLONG_MAX, R = LLONG_MIN;

    for (int i = 0; i < N; i++) {
        cin >> p[i] >> w[i] >> d[i];
        L = min(L, p[i] - d[i]);
        R = max(R, p[i] + d[i]);
    }

    auto cost = [&](long long x) {
        long long total = 0;
        for (int i = 0; i < N; i++) {
            long long dist = llabs(x - p[i]);
            if (dist > d[i]) {
                total += (dist - d[i]) * w[i];
            }
        }
        return total;
    };

    while (R - L > 10) {
        long long m1 = L + (R - L) / 3;
        long long m2 = R - (R - L) / 3;

        if (cost(m1) <= cost(m2)) {
            R = m2;
        } else {
            L = m1;
        }
    }

    long long ans = LLONG_MAX;
    for (long long x = L; x <= R; x++) {
        ans = min(ans, cost(x));
    }

    cout << ans << "\n";
    return 0;
}
