#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll p = 998244353;
vector<ll> f(200005, 1);

ll exp(ll a, int e) {
    if (e == 0) {
        return 1;
    }
    if (e % 2) {
        return (a * exp(a, e - 1)) % p;
    } else {
        ll r = exp(a, e / 2);
        return (r * r) % p;
    }
}

ll inv(ll a) {
    return exp(a, p - 2);
}

ll C(ll n, ll k) {
    return (f[n] * inv((f[n - k] * f[k]) % p)) % p;
}

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 2) {
        cout << "0\n";
        return;
    }
    for (ll i = 1; i <= m; i++)
        f[i] = (i * f[i - 1]) % p;
    ll r = (((C(m, n - 1) * (n - 2)) % p) * exp(2, n - 3)) % p;
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
