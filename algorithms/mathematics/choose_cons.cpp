#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> F(n + 1);
    for (int i = 0; i < n; i++) {
        F[i + 1] = F[i] + (s[i] - '0');
    }
    if (F[n] < k) {
        cout << "1\n";
        return;
    }
    ll p = 998244353;
    vector<vector<ll>> C(n + 1);
    for (int i = 0; i <= n; i++) {
        C[i].resize(i + 1);
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
        }
    }
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int c = F[j + 1] - F[i];
            if (c <= k) {
                if (s[i] == '0') c--;
                if (s[j] == '0') c--;
                if (0 <= c && c <= j - i - 1) {
                    ans = (ans + C[j - i - 1][c]) % p;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
