#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> S;
vector<int> V, T, C, I;
vector<vector<int>> adj;

struct FenwickTree {
    int n;
    vector<ll> T;
    ll sum(int i) {
        ll s = 0;
        for (; i; i &= ~(i & -i))
            s += T[i];
        return s;
    }
    void add(int i, int x) {
        for (; i < n; i += i & -i)
            T[i] += x;
    }
    ll query(int l, int r) {
        if (r < l) return 0;
        return sum(r) - sum(l - 1);
    }
    FenwickTree(vector<ll> A) {
        T = A;
        n = (int)A.size();
        for (int i = 1; i < n; i++)
            T[i] = A[i];
        for (int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if (j < n)
                T[j] += T[i];
        }
    }
};

void dfs(int v, int p, ll s) {
    C[v] = 1;
    S[v] = s + V[v];
    T.push_back(v);
    I[v] = int(T.size());
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, s + V[v]);
            C[v] += C[u];
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    S.resize(n); V.resize(n);
    C.resize(n); I.resize(n);
    for (int &v : V) {
        cin >> v;
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
    vector<ll> A(n + 2);
    FenwickTree T(A);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int v, x;
            cin >> v >> x;
            v--;
            T.add(I[v], x - V[v]);
            T.add(I[v] + C[v], V[v] - x);
            V[v] = x;
        } else {
            int v;
            cin >> v;
            v--;
            cout << S[v] + T.query(1, I[v]) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}