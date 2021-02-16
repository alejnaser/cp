#include<bits/stdc++.h>
using namespace std;

struct FenwickTree {
    int n;
    vector<int> T;
    int sum(int i) {
        int s = 0;
        for (; i; i &= ~(i & -i))
            s += T[i];
        return s;
    }
    void add(int i, int x) {
        for (; i < n; i += i & -i)
            T[i] += x;
    }
    int query(int l, int r) {
        if (r < l) return 0;
        return sum(r) - sum(l - 1);
    }
    FenwickTree(vector<int> A) {
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

void solve() {
    long long ans = 1;
    int n, k; cin >> n >> k;
    int idx = 1; bool s = k > n / 2;
    vector<int> A(n + 1); FenwickTree T(A);
    for (int i = 0; i < n; i++) {
        int l = idx, r = idx + k; idx = r; 
        if (idx > n) {
            r   -= n; 
            idx -= n;
        }
        if (s) swap(l, r);
        T.add(l, 1); T.add(r, 1);
        if (l < r) 
            ans += T.query(l + 1, r - 1) + 1;
        else 
            ans += T.query(l + 1, n) + T.query(1, r - 1) + 1;
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}