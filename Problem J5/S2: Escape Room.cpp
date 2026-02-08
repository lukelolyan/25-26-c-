#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1000001];
bool visited[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    if (!(cin >> M >> N)) return 0;

    for (int r = 1; r <= M; ++r) {
        for (int c = 1; c <= N; ++c) {
            int val;
            cin >> val;
            adj[r * c].push_back(val);
        }
    }

    queue<int> q;
    int start_val = M * N;
    
    
    int initial_value;
}
