#include<bits/stdc++.h>
using namespace std;

vector<string> M(1000);
int n, m, vis[1000][1000];

int X[] = {-1, 0, 1, 0};
int Y[] = {0, -1, 0, 1};

bool ok(int r, int c) {
    return 0 <= r && r < n &&
           0 <= c && c < m &&
           !vis[r][c] && M[r][c] == '.';
}

void dfs(int r, int c) {
    vis[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int rr = r + X[i];
        int cc = c + Y[i];
        if (ok(rr, cc))
            dfs(rr, cc);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> M[i];
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j] && M[i][j] == '.') {
                dfs(i, j);
                ans++;
            }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}