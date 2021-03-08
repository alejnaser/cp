#include<bits/stdc++.h>
using namespace std;

#define INF 1e18
typedef long long ll;

// complexity: O(nm)

void solve() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    vector<ll> dist(n + 1);
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[1] = 0;
    for (int i = 1; i < n; i++)
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = min(dist[b], dist[a] + w);
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
