#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

struct RLEPart {
    char ch;
    ll count;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    ll c;
    if (!(cin >> S >> c)) return 0;

    vector<RLEPart> pattern;
    ll total_length = 0;

    for (int i = 0; i < S.length(); ) {
        char current_char = S[i];
        i++;
        
        string num_str = "";
        while (i < S.length() && isdigit(S[i])) {
            num_str += S[i];
            i++;
        }
        
        ll current_count = stoll(num_str);
        pattern.push_back({current_char, current_count});
        total_length += current_count;
    }
    ll relative_index = c % total_length;

    for (const auto& part : pattern) {
        if (relative_index < part.count) {
            cout << part.ch << endl;
            break;
        }
        relative_index -= part.count;
    }

    return 0;
}
