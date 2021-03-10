#include<bits/stdc++.h>
using namespace std;

#define INF 1e18
typedef long long ll;

// complexity: O(n^3)

void solve() {
    int n, m, q; cin >> n >> m >> q;
    int adj[505][505]; ll dist[505][505];
    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (adj[a][b]) {
            adj[a][b] = adj[b][a] = min(adj[a][b], c);
        } else {
            adj[a][b] = adj[b][a] = c;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                dist[i][j] = 0;
            else if (adj[i][j])
                dist[i][j] = adj[i][j];
            else
                dist[i][j] = INF;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    while (q--) {
        int a, b; cin >> a >> b;
        if (dist[a][b] == INF)
            dist[a][b] = -1;
        cout << dist[a][b] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
