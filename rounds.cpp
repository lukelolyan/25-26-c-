#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
struct Edge {
    int u, v;
    long long l, c;
    int id; 
    bool active; 
};


struct AdjEntry {
    int v;
    long long l;
    int edge_index;
};

const long long INF = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<Edge> edges;
    long long total_cost = 0;

    for (int i = 0; i < M; ++i) {
        int u, v;
        long long l, c;
        cin >> u >> v >> l >> c;
 
        edges.push_back({u - 1, v - 1, l, c, i, true});
        total_cost += c;
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        if (a.c != b.c) return a.c > b.c; 
        return a.l > b.l; 
    });

    vector<vector<AdjEntry>> adj(N);
    for (int i = 0; i < M; ++i) {
        adj[edges[i].u].push_back({edges[i].v, edges[i].l, i});
        adj[edges[i].v].push_back({edges[i].u, edges[i].l, i});
    }

    for (int i = 0; i < M; ++i) {
 
        edges[i].active = false;

        int start_node = edges[i].u;
        int target_node = edges[i].v;
        long long target_dist = edges[i].l;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(N, INF);

        dist[start_node] = 0;
        pq.push({0, start_node});

        bool path_exists = false;

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;
            if (u == target_node) {
                if (d <= target_dist) {
                    path_exists = true;
                }
                break; 
            }
            if (d > target_dist) continue;

            for (const auto& edge_entry : adj[u]) {
      
                if (edges[edge_entry.edge_index].active) {
                    int v = edge_entry.v;
                    long long weight = edge_entry.l;
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
        }

        if (path_exists) {
    
            total_cost -= edges[i].c;
        } else {
      
            edges[i].active = true;
        }
    }

    cout << total_cost << endl;

    return 0;
}
