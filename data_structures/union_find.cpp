#include<bits/stdc++.h>
using namespace std;

#define PB push_back

vector<int> lk(1050);
vector<int> sz(1050);

int find(int x) {
    while (x != lk[x]) x = lk[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (sz[a] < sz[b])
        swap(a, b);
    sz[a] += sz[b];
    lk[b] = a;
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        lk[i] = i;
        sz[i] = 1;
    }
    vector<int> R, X, Y;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        if (find(a) == find(b))
            {X.PB(a), Y.PB(b);}
        else
            unite(a, b);
    }
    R.PB(find(1));
    for (int i = 1; i <= n; i++)
        if (find(1) != find(i)) {
            R.PB(find(i));
            unite(1, i);
        }
    cout << X.size() << '\n';
    for (int i = 0; i < (int)X.size(); i++) {
        cout << X[i] << " " << Y[i] << " ";
        cout << R[i] << " " << R[i + 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}