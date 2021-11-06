#include<bits/stdc++.h>
using namespace std;
 
int pos = 0;
vector<int> P, D, H, C, T, I;
vector<vector<int>> A, L;
 
vector<int> st(524288);
 
int st_query(int a, int b) {
    int p = 262144;
    a += p; b += p;
    int m = 0;
    while (a <= b) {
        if (a % 2 == 1) m = max(m, st[a++]);
        if (b % 2 == 0) m = max(m, st[b--]);
        a /= 2; b /= 2;
    }
    return m;
}
 
void st_update(int k, int x) {
    int p = 262144;
    k += p;
    st[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        st[k] = max(st[2 * k], st[2 * k + 1]);
    }
}
 
void dfs(int v, int p) {
    C[v] = 1;
    L[v][0] = p;
    int max_sz = 0;
    for (int u : A[v]) {
        if (u != p) {
            P[u] = v;
            D[u] = D[v] + 1;
            dfs(u, v);
            C[v] += C[u];
            if (C[u] > max_sz) {
                max_sz = C[u];
                H[v] = u;
            }
        }
    }
}
 
int anc(int x, int k) {
    int c = x;
    int n = int(L.size());
    int m = int(log2(n)) + 1;
    for (int i = 0; i < m; i++) {
        if (k & (1 << i)) {
            c = L[c][i];
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
    int n = int(L.size());
    int m = int(log2(n)) + 1;
    for (int i = m - 1; ~i; i--) {
        int ua = L[u][i];
        int va = L[v][i];
        if (ua != va) {
            u = ua;
            v = va;
        }
    }
    return L[u][0];
}
 
void hld(int v, int h) {
    T[v] = h;
    I[v] = pos++;
    if (H[v] != -1) {
        hld(H[v], h);
    }
    for (int u : A[v]) {
        if (u != P[v] && u != H[v]) {
            hld(u, u);
        }
    }
}
 
int query(int a, int b) {
    int r = 0;
    for (; T[a] != T[b]; b = P[T[b]]) {
        if (D[T[a]] > D[T[b]]) {
            swap(a, b);
        }
        r = max(r, st_query(I[T[b]], I[b]));
    }
    if (D[a] > D[b]) {
        swap(a, b);
    }
    r = max(r, st_query(I[a], I[b]));
    return r;
}
 
void update(int v, int x) {
    st_update(I[v], x);
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    P.resize(n);
    D.resize(n);
    C.resize(n);
    A.resize(n);
    T.resize(n);
    I.resize(n);
    H.resize(n, -1);
    L.resize(n);
    int m = int(log2(n)) + 1;
    for (int i = 0; i < n; i++) {
        L[i].resize(m);
    }
    vector<int> V(n);
    for (int &v : V) {
        cin >> v;
    }
    for (int _ = 0; _ < n - 1; _++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    dfs(0, 0);
    hld(0, 0);
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            L[i][j] = L[L[i][j - 1]][j - 1];
        }
    }
    for (int v = 0; v < n; v++) {
        st_update(I[v], V[v]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            s--;
            st_update(I[s], x);
        } else {
            int u, v;
            cin >> u >> v;
            u--, v--;
            int l = lca(u, v);
            // cout << u << " " << l << " " << query(u, l) << endl;
            // cout << v << " " << l << " " << query(v, l) << endl;
            cout << max({query(u, l), query(l, v)}) << ' ';
        }
    }
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}