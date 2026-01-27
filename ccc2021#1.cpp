#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    int ans = 0;

    for (int b = 0; b * 5 <= N; ++b) {

        int remainder = N - (b * 5);

        if (remainder % 4 == 0) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
