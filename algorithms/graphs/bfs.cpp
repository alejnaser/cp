#include<bits/stdc++.h>
using namespace std;

#define N 1000
#define F first
#define S second

string D = "ULDR";
int X[] = {-1, 0, 1, 0};
int Y[] = {0, -1, 0, 1};

int n, m;
pair<int, int> A, B;
vector<string> M(N);
int VI[N][N], PX[N][N], PY[N][N], DD[N][N];

bool ok(int r, int c) {
    return 0 <= r && r < n &&
           0 <= c && c < m &&
           !VI[r][c] && M[r][c] == '.';
}

void bfs(pair<int, int> V) {
    queue<pair<int, int>> q;
    q.push(V);
    VI[V.F][V.S] = 1;
    M[B.F][B.S] = '.';
    while (!q.empty()) {
        pair<int, int> t = q.front(); q.pop();
        int r = t.F, c = t.S;
        if (B == make_pair(r, c)) {
            string ans;
            int nr, nc;
            while (A != make_pair(r, c)) {
                ans += DD[r][c];
                nr = PX[r][c];
                nc = PY[r][c];
                r = nr;
                c = nc;
            }
            reverse(ans.begin(), ans.end());
            cout << "YES\n";
            cout << ans.size() << '\n';
            cout << ans << '\n';
            exit(0);
        }
        for (int i = 0; i < 4; i++) {
            int x = r + X[i];
            int y = c + Y[i];
            if (ok(x, y)) {
                VI[x][y] = 1;
                PX[x][y] = r;
                PY[x][y] = c;
                DD[x][y] = D[i];
                q.push({x, y});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    memset(VI, 0, sizeof(VI));
    for (int i = 0; i < n; i++) {
        cin >> M[i];
        for (int j = 0; j < m; j++) {
            if (M[i][j] == 'A')
                A = {i, j};
            if (M[i][j] == 'B')
                B = {i, j};
        }
    }
    bfs(A);
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}