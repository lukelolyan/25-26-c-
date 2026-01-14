#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    if (!(cin >> C)) return 0;

    vector<int> row1(C);
    vector<int> row2(C);
    int black_tiles_count = 0;

    for (int i = 0; i < C; ++i) {
        cin >> row1[i];
        if (row1[i] == 1) {
            black_tiles_count++;
        }
    }
    for (int i = 0; i < C; ++i) {
        cin >> row2[i];
        if (row2[i] == 1) {
            black_tiles_count++;
        }
    }

    long long tape_length = (long long)black_tiles_count * 3;

    for (int i = 0; i < C - 1; ++i) {
        if (row1[i] == 1 && row1[i+1] == 1) {
            tape_length -= 2;
        }
        if (row2[i] == 1 && row2[i+1] == 1) {
            tape_length -= 2;
        }
    }
    for (int i = 0; i < C; i += 2) {
        if (row1[i] == 1 && row2[i] == 1) {
            tape_length -= 2;
        }
    }

    cout << tape_length << endl;

    return 0;
}
