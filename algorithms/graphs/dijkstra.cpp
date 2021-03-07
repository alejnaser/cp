#include<bits/stdc++.h>
using namespace std;

#define INF 1e9+5
#define PB push_back

int n;
vector<int> dist(100005, INF);
vector<pair<int, int>> adj[100005];

void dijkstra(int x) {
    bitset<100005> vis;
    priority_queue<pair<int, int>> q;
    dist[x] = 0;
    q.push({0, x});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (vis[a])
            continue;
        vis[a] = 1;
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
}

void solve() {
    n = 5;
    adj[1].PB({2, 5}); adj[2].PB({1, 5});
    adj[1].PB({4, 9}); adj[4].PB({1, 9});
    adj[1].PB({5, 1}); adj[5].PB({1, 1});
    adj[2].PB({3, 2}); adj[3].PB({2, 2});
    adj[3].PB({4, 6}); adj[4].PB({3, 6});
    adj[4].PB({5, 2}); adj[5].PB({4, 2});

    dijkstra(1);
    for (int i = 1; i <= n; i++)
        printf("dist from (1) to (%d) = %d\n", i, dist[i]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
