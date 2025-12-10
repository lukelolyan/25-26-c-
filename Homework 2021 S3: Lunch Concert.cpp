#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int64> P(N), W(N), D(N);
    for (int i = 0; i < N; i++) cin >> P[i] >> W[i] >> D[i];

    vector<pair<int64,int64>> L, R;
    L.reserve(N);
    R.reserve(N);
    int64 totalW = 0;

    for (int i = 0; i < N; i++) {
        int64 Li = P[i] - D[i];
        int64 Ri = P[i] + D[i];
        L.push_back({Li, W[i]});
        R.push_back({Ri, W[i]});
        totalW += W[i];
    }

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    vector<int64> Lpos(N), Rpos(N);
    vector<int64> Lw(N+1,0), Lwx(N+1,0), Rw(N+1,0), Rwx(N+1,0);

    for (int i = 0; i < N; i++) {
        Lpos[i] = L[i].first;
        Rpos[i] = R[i].first;
    }

    for (int i = 0; i < N; i++) {
        Lw[i+1] = Lw[i] + L[i].second;
        Lwx[i+1] = Lwx[i] + L[i].second * L[i].first;
        Rw[i+1] = Rw[i] + R[i].second;
        Rwx[i+1] = Rwx[i] + R[i].second * R[i].first;
    }

    auto sum_L_le = [&](int64 c) {
        int idx = upper_bound(Lpos.begin(), Lpos.end(), c) - Lpos.begin();
        return pair<int64,int64>(Lw[idx], Lwx[idx]);
    };

    auto sum_R_le = [&](int64 c) {
        int idx = upper_bound(Rpos.begin(), Rpos.end(), c) - Rpos.begin();
        return pair<int64,int64>(Rw[idx], Rwx[idx]);
    };

    auto g = [&](int64 c) {
        auto Lsum = sum_L_le(c);
        auto Rsum = sum_R_le(c);
        int64 wL_le = Lsum.first;
        int64 wR_le = Rsum.first;
        return -(totalW - wL_le) + wR_le;
    };

    int64 minL = Lpos[0];
    int64 maxR = Rpos[N-1];

    int64 lo = minL - 1;
    int64 hi = maxR;

    while (lo < hi) {
        int64 mid = (lo + hi) >> 1;
        if (g(mid) >= 0) hi = mid;
        else lo = mid + 1;
    }

    int64 cand = lo;

    function<int64(int64)> f = [&](int64 c) {
        auto Lsum = sum_L_le(c);
        int64 wL_le = Lsum.first;
        int64 wLx_le = Lsum.second;

        int64 wL_gt = totalW - wL_le;
        int64 wLx_gt = Lwx[N] - wLx_le;
        int64 left = wLx_gt - c * wL_gt;

        auto Rsum = sum_R_le(c);
        int64 wR_le = Rsum.first;
        int64 wRx_le = Rsum.second;
        int64 right = c * wR_le - wRx_le;

        return left + right;
    };

    int64 ans = f(cand);
    ans = min(ans, f(cand - 1));

    cout << ans << "\n";
}
