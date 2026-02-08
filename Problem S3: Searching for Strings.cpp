#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD1 = 1e9 + 7, BASE1 = 31;
const ll MOD2 = 1e9 + 9, BASE2 = 37;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string N, H;
    cin >> N >> H;

    int nLen = N.length();
    int hLen = H.length();

    if (nLen > hLen) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> targetFreq(26, 0);
    for (char c : N) targetFreq[c - 'a']++;
    vector<int> windowFreq(26, 0);
    ll h1 = 0, h2 = 0;
    ll p1 = 1, p2 = 1;

    for (int i = 0; i < nLen - 1; i++) {
        p1 = (p1 * BASE1) % MOD1;
        p2 = (p2 * BASE2) % MOD2;
    }

    set<pair<ll, ll>> distinctPerms;

    for (int i = 0; i < hLen; i++) {
    
        windowFreq[H[i] - 'a']++;
        h1 = (h1 * BASE1 + (H[i] - 'a' + 1)) % MOD1;
        h2 = (h2 * BASE2 + (H[i] - 'a' + 1)) % MOD2;

        if (i >= nLen) {
            int leftIdx = i - nLen;
            windowFreq[H[leftIdx] - 'a']--;
            h1 = (h1 - (H[leftIdx] - 'a' + 1) * p1 % MOD1 + MOD1) % MOD1;
            h2 = (h2 - (H[leftIdx] - 'a' + 1) * p2 % MOD2 + MOD2) % MOD2;
        }

        if (i >= nLen - 1) {
            bool match = true;
            for (int j = 0; j < 26; j++) {
                if (windowFreq[j] != targetFreq[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                distinctPerms.insert({h1, h2});
            }
        }
    }

    cout << distinctPerms.size() << endl;

    return 0;
}
