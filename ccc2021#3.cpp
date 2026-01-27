#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, C;
    if (!(cin >> N >> C)) return 0;

    vector<long long> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P.begin(), P.end());

    long long total_triplets = N * (N - 1) * (N - 2) / 6;

    vector<long long> P_ext = P; 
    for (long long val : P) {
        P_ext.push_back(val + C);
    }
    long long bad_semicircle = 0;
    
    int right = 1; 
    for (int i = 0; i < N; i++) {
        while (right < 2 * N && 2 * (P_ext[right] - P_ext[i]) < C) {
            right++;
        }
        
        long long k = right - i - 1;
        
        if (k >= 2) {
            bad_semicircle += k * (k - 1) / 2;
        }
    }

    long long bad_antipodal = 0;

    if (C % 2 == 0) {
        long long half_C = C / 2;
        long long antipodal_pairs = 0;
        for (int i = 0; i < N; i++) {
            long long target = P[i] + half_C;
            
            auto lb = lower_bound(P.begin(), P.end(), target);
            auto ub = upper_bound(P.begin(), P.end(), target);
            
            long long count = ub - lb;
            antipodal_pairs += count;
        }
        
        antipodal_pairs /= 2;
        bad_antipodal = antipodal_pairs * (N - 2);
    }

    long long good_triplets = total_triplets - bad_semicircle - bad_antipodal;
    
    cout << good_triplets << endl;

    return 0;
}
