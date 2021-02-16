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
 
void solve() {
    int n; cin >> n;
    UnionFind uf(n);
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        if (uf.find(i) != uf.find(p)) 
            uf.join(i, p);
    }
    cout << uf.size << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}