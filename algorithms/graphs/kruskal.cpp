#include<bits/stdc++.h>
using namespace std;

struct UnionFind {
    int size;
    vector<int> P, S;
    int find(int x) {
        while (x != P[x])
            x = P[x];
        return x;
    }
    void join(int a, int b) {
        a = find(a); b = find(b);
        if (S[a] < S[b])
            swap(a, b);
        P[b]  = a;
        S[a] += S[b];
        size--;
    }
    UnionFind(int n) {
        size = n;
        P.resize(n + 1); S.resize(n + 1);
        for (int i = 1; i <= n; i++)
            S[i] = 1, P[i] = i;
    }
};

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<2>(a) < get<2>(b);
}

// complexity: O(m log n)

void solve() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges.emplace_back(a, b, w);
    }
    sort(edges.begin(), edges.end(), cmp);
    UnionFind uf(n);
    vector<tuple<int, int>> mst;
    int W = 0;
    for (auto [a, b, w] : edges) {
        if (uf.find(a) != uf.find(b)) {
            uf.join(a, b);
            mst.emplace_back(a, b);
            W += w;
        }
    }
    cout << "MST weight: " << W << '\n';
    for (auto [a, b] : mst)
        cout << a << ' ' << b << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
