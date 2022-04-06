#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

void solve() {
    int n;
    cin >> n;
    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    indexed_set S;
    int L = 0, R = 0, INF = 1e9;
    for (int i = 0; i < n; i++) {
        S.insert(B[i]);
        int p = S.order_of_key(B[i]);
        int l = p + L;
        int r = int(S.size()) - p - 1 + R;
        if (max(l, r) > i) {
            cout << "NO\n";
            return;
        }
        L += i - l;
        R += i - r;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}