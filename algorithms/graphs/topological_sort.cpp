#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

vector<int> ts, path;
vector<int> adj[100005], state(100005);

void dfs(int v) {
    state[v] = 1;
    path.push_back(v);
    for (int u : adj[v]) {
        if (state[u] == 1) {
            cout << "The graph contains a cycle:\n";
            vector<int> cycle;
            cycle.push_back(u);
            while (path.back() != u) {
                cycle.push_back(path.back());
                path.pop_back();
            }
            cycle.push_back(u);
            reverse(all(cycle));
            for (int c : cycle)
                cout << c << ' ';
            cout << '\n';
            exit(0);
        }
        if (state[u] == 0)
            dfs(u);
    }
    state[v] = 2;
    path.pop_back();
    ts.push_back(v);
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
        if (state[i] == 0)
            dfs(i);
    reverse(all(ts));
    for (int v : ts)
        cout << v << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
