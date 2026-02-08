#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> b(N);
    int max_type = 0;
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
        if (b[i] > max_type) max_type = b[i];
    }

    int coach_type = b[0];
    int josh_type = b[N - 1];

    if (coach_type == josh_type) {
        cout << fixed << setprecision(10) << 1.0 << endl;
        return 0;
    }

    vector<int> cnt(max_type + 1, 0);
    vector<int> last_occ(max_type + 1, -1);
    for (int i = 0; i < N; ++i) {
        cnt[b[i]]++;
        last_occ[b[i]] = i;
    }

    vector<double> f(N, 0.0);
    double S = 0.0;

    for (int i = N - 2; i >= 1; --i) {
        int type = b[i];
        if (i == last_occ[type]) {

            if (type != coach_type && type != josh_type) {
                f[i] = (cnt[coach_type] + S) / (double)(N - i);
                S += (double)cnt[type] * f[i];
            }
        }
    }
    double ans = (cnt[coach_type] + S) / (double)N;

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
