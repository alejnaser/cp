#include<bits/stdc++.h>
using namespace std;

int n, m, R = -1;
vector<int> D, C, I, P, dp;
vector<vector<int>> adj, adjC, A;

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
    int n2 = int(A.size());
    int m2 = int(log2(n2)) + 1;
    for (int i = 0; i < m2; i++) {
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
    int n2 = int(A.size());
    int m2 = int(log2(n2)) + 1;
    for (int i = m2 - 1; ~i; i--) {
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

void dfs2(int v, int p) {
    C[v] = 1;
    for (int u : adj[v]) {
        if (u != p && !I[u]) {
            dfs2(u, v);
            C[v] += C[u];
        }
    }
}

int centroid(int v, int p, int sz) {
    for (int u : adj[v]) {
        if (!I[u] && u != p && C[u] > sz / 2) {
            return centroid(u, v, sz);
        }
    }
    return v;
}

int rec(int v) {
    dfs2(v, v);
    int c = centroid(v, v, C[v]);
    if (R == -1) {
        R = c;
    }
    I[c] = 1;
    for (int u : adj[c]) {
        if (!I[u]) {
            int c2 = rec(u);
            adjC[c].push_back(c2);
            P[c2] = c;
        }
    }
    return c;
}

void dfs3(int v) {
    dp[v] = dst(v, 0);
    for (int u : adjC[v]) {
        dfs3(u);
        dp[v] = min(dp[v], dp[u] + dst(u, v));
    }
}

void solve() {
    cin >> n >> m;
    adj.resize(n);
    adjC.resize(n);
    A.resize(n); C.resize(n);
    D.resize(n); I.resize(n);
    P.resize(n, -1); dp.resize(n);
    for (int i = 0; i < n; i++) {
        A[i].resize(int(log2(n)) + 1);
    }
    for (int _ = 0; _ < n - 1; _++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0, 0);
    for (int j = 1; j < int(log2(n)) + 1; j++) {
        for (int i = 0; i < n; i++) {
            A[i][j] = A[A[i][j - 1]][j - 1];
        }
    }
    rec(0);
    dfs3(R);
    while (m--) {
        int t, v;
        cin >> t >> v;
        v--;
        if (t == 1) {
            for (int c = v; c != -1; c = P[c]) {
                dp[c] = min(dp[c], dst(c, v));
            }
        } else {
            int a = n;
            for (int c = v; c != -1; c = P[c]) {
                a = min(a, dp[c] + dst(c, v));
            }
            cout << a << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}