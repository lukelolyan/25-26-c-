#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Edge {
    int to;
    int temp;
};

struct Node {
    int room;
    int temp;
    ll dist;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

// Maps (room, temperature) to a unique integer ID for Dijkstra
map<pair<int, int>, int> node_map;
int get_id(int r, int t) {
    pair<int, int> p = {r, t};
    if (node_map.find(p) == node_map.end()) {
        int new_id = node_map.size();
        node_map[p] = new_id;
    }
    return node_map[p];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    // Store temperatures associated with each room
    vector<vector<int>> room_temps(N + 1);
    struct Tunnel { int u, v, c; };
    vector<Tunnel> tunnels;

    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        tunnels.push_back({u, v, c});
        room_temps[u].push_back(c);
        room_temps[v].push_back(c);
    }

    vector<vector<pair<int, int>>> adj(2 * M + 5); 

    for (int i = 1; i <= N; ++i) {
        sort(room_temps[i].begin(), room_temps[i].end());
        room_temps[i].erase(unique(room_temps[i].begin(), room_temps[i].end()), room_temps[i].end());

        for (int j = 0; j < (int)room_temps[i].size() - 1; ++j) {
            int u = get_id(i, room_temps[i][j]);
            int v = get_id(i, room_temps[i][j+1]);
            int cost = room_temps[i][j+1] - room_temps[i][j];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }
    }
    for (const auto& t : tunnels) {
        int u_id = get_id(t.u, t.c);
        int v_id = get_id(t.v, t.c);
        adj[u_id].push_back({v_id, 0});
        adj[v_id].push_back({u_id, 0});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(node_map.size(), INF);

    for (int t : room_temps[1]) {
        int id = get_id(1, t);
        dist[id] = t;
        pq.push({dist[id], id});
    }

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            if (dist[u] + edge.second < dist[edge.first]) {
                dist[edge.first] = dist[u] + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }

    ll ans = INF;
    for (int t : room_temps[N]) {
        ans = min(ans, dist[get_id(N, t)]);
    }

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}
