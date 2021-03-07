#include<bits/stdc++.h>
using namespace std;

#define INF 1e9+5
#define PB push_back

int n;
vector<int> dist(100005, INF);
vector<tuple<int, int, int>> edg;

void bellman_ford(int x) {
    dist[x] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (auto e : edg) {
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = min(dist[b], dist[a] + w);
        }
    }
}

void solve() {
    n = 5;
    edg.PB({1, 2,  2});
    edg.PB({1, 3,  3});
    edg.PB({1, 4,  7});
    edg.PB({2, 4,  3});
    edg.PB({2, 5,  5});
    edg.PB({3, 4, -2});
    edg.PB({4, 5,  2});
    bellman_ford(1);
    for (int i = 1; i <= n; i++)
        printf("dist from (1) to (%d) = %d\n", i, dist[i]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
