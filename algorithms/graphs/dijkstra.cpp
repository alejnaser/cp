#include<bits/stdc++.h>
using namespace std;

#define INF 1e18
typedef long long ll;

// complexity: O(n + m log m)

void solve() {
    int n, m; cin >> n >> m;
    bitset<100005> vis;
    vector<ll> dist(n + 1, INF);
    vector<pair<int, int>> adj[n + 1];
    priority_queue<pair<ll, int>> q;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dist[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (vis[a])
            continue;
        vis[a] = true;
        for (auto u : adj[a]) {
            int b = u.first;
            ll w = u.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
