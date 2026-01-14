#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, R, C;
    if (!(cin >> N >> M >> R >> C)) return 0;

    if (R == N && C < M) {
        if (M % 2 == 0 && C % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    if (C == M && R < N) {
        if (N % 2 == 0 && R % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    vector<string> grid(N, string(M, 'a'));

    if (R == N) {
        int needed = M - C;
        for (int j = 0; j < M; ++j) {
            if (needed <= 0) break;
            
            int mirror = M - 1 - j;
            if (j > mirror) break; 

            if (j == mirror) {
                grid[0][j] = 'b';
                needed--;
            } else {
                if (needed >= 2) {
                    grid[0][j] = 'b';
                    grid[0][mirror] = 'b';
                    needed -= 2;
                }
            }
        }
    } 
    else if (C == M) {
        int needed = N - R;
        for (int i = 0; i < N; ++i) {
            if (needed <= 0) break;
            
            int mirror = N - 1 - i;
            if (i > mirror) break;

            if (i == mirror) {
                grid[i][0] = 'b';
                needed--;
            } else {
                if (needed >= 2) {
                    grid[i][0] = 'b';
                    grid[mirror][0] = 'b';
                    needed -= 2;
                }
            }
        }
    } 
    else {
        for (int i = R; i < N; ++i) {
            grid[i][M - 1] = 'b';
        }
        
        for (int j = C; j < M; ++j) {
            grid[N - 1][j] = 'b';
        }


        if (C == 0) {
            grid[N - 1][0] = 'c';
        }
        
        if (R == 0) {
            grid[0][M - 1] = 'c';
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << grid[i] << endl;
    }

    return 0;
}
