#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll N = 200005;
ll p = 998244353;
vector<ll> F(N);

void precalc_F() {
    F[0] = 1;
    for (ll i = 1; i < N; i++)
        F[i] = (i * F[i - 1]) % p;
}

ll exp(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1)
            r = (r * a) % p;
        a = (a * a) % p;
        e >>= 1;
    }
    return r;
}

ll inv(ll a) {
    return exp(a, p - 2);
}

ll choose(ll n, ll k) {
    return (F[n] * inv((F[n - k] * F[k]) % p)) % p;
}

void solve() {
    precalc_F();
    ll n, m; cin >> n >> m;
    ll r = n - 2;
    for (int i = 0; i < n - 3; i++) 
        r = (r * 2) % p;
    r = (r * choose(m, n - 1)) % p;
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}