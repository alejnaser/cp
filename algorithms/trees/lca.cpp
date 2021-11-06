#include<bits/stdc++.h>
using namespace std;
 
vector<int> D;
vector<vector<int>> adj, A;
 
void dfs(int v, int p, int d) {
    D[v] = d;
    A[v][0] = p;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
        }
    }
}
 
int anc(int x, int k) {
    int c = x;
    int n = int(A.size());
    int m = int(log2(n)) + 1;
    for (int i = 0; i < m; i++) {
        if (k & (1 << i)) {
            c = A[c][i];
        }
    }
    return c;
}
 
int lca(int u, int v) {
    if (D[u] > D[v]) {
        swap(u, v);
    }
    v = anc(v, D[v] - D[u]);
    if (u == v) {
        return u;
    }
    int n = int(A.size());
    int m = int(log2(n)) + 1;
    for (int i = m - 1; ~i; i--) {
        int ua = A[u][i];
        int va = A[v][i];
        if (ua != va) {
            u = ua;
            v = va;
        }
    }
    return A[u][0];
}
 
int dst(int u, int v) {
    return D[u] + D[v] - 2 * D[lca(u, v)];
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    A.resize(n);
    D.resize(n);
    int m = int(log2(n)) + 1;
    for (int i = 0; i < n; i++) {
        A[i].resize(m);
    }
    adj.resize(n);
    for (int _ = 0; _ < n - 1; _++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0, 0);
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            A[i][j] = A[A[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << dst(a - 1, b - 1) << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}