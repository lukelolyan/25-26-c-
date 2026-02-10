#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Pen {
    int color;
    int prettiness;
};

int N, M, Q;
vector<Pen> pens;
vector<multiset<int>> color_groups;
multiset<int> all_b1, all_b2;
ll sum_b1 = 0;

void update_color_stats(int c, bool removing) {
    if (color_groups[c].empty()) return;

    auto it = color_groups[c].rbegin();
    int b1 = *it;
    int b2 = (color_groups[c].size() > 1) ? *(++it) : 0;

    if (removing) {
        sum_b1 -= b1;
        all_b1.erase(all_b1.find(b1));
        all_b2.erase(all_b2.find(b2));
    } else {
        sum_b1 += b1;
        all_b1.insert(b1);
        all_b2.insert(b2);
    }
}

ll calculate_max_prettiness() {
    int min_b1 = *all_b1.begin();
    int max_b2 = *all_b2.rbegin();
    return sum_b1 + max(0, max_b2 - min_b1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> N >> M >> Q)) return 0;

    pens.resize(N + 1);
    color_groups.resize(M + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> pens[i].color >> pens[i].prettiness;
        color_groups[pens[i].color].insert(pens[i].prettiness);
    }

    for (int i = 1; i <= M; ++i) {
        update_color_stats(i, false);
    }

    cout << calculate_max_prettiness() << "\n";

    for (int k = 0; k < Q; ++k) {
        int type, idx, val;
        cin >> type >> idx >> val;

        int old_color = pens[idx].color;
        update_color_stats(old_color, true);
        
        if (type == 1) { 
            color_groups[old_color].erase(color_groups[old_color].find(pens[idx].prettiness));
            update_color_stats(old_color, false);

            pens[idx].color = val;
            update_color_stats(pens[idx].color, true);
            color_groups[pens[idx].color].insert(pens[idx].prettiness);
            update_color_stats(pens[idx].color, false);
        } else { 
            color_groups[old_color].erase(color_groups[old_color].find(pens[idx].prettiness));
            pens[idx].prettiness = val;
            color_groups[old
