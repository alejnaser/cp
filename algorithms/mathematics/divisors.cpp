#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

ll exp(ll b, ll e) {
    if (e == 0) {
        return 1;
    }
    if (e % 2) {
        return (b * exp(b, e - 1)) % mod;
    } else {
        ll t = exp(b, e / 2);
        return (t * t) % mod;
    }
}

ll inv(ll a) {
    return exp(a, mod - 2);
}

ll divs_cnt(vector<pair<int, int>> fac) {
    ll c = 1;
    for (auto [_, e] : fac) {
        c = (c * (e + 1)) % mod;
    }
    return c;
}

ll divs_sum(vector<pair<int, int>> fac) {
    ll s = 1;
    for (auto [p, e] : fac) {
        ll t = ((exp(p, e + 1) - 1) * inv(p - 1)) % mod;
        s = (s * t) % mod;
    }
    return s;
}

ll divs_prd(vector<pair<int, int>> fac) {
    bool any = false;
    for (auto [_, e] : fac) {
        any |= e & 1;
    }
    if (any) {
        ll n = 1;
        for (auto [p, e] : fac) {
            n = (n * exp(p, e)) % mod;
        }
        any = false;
        for (auto [p, e] : fac) {
            if (e & 1 && !any) {
                n = exp(n, (e + 1) / 2);
                any = true;
            } else {
                n = exp(n, e + 1);
            }
        }
        return n;
    } else {
        ll n = 1;
        for (auto [p, e] : fac) {
            n = (n * exp(p, e / 2)) % mod;
        }
        for (auto [p, e] : fac) {
            n = exp(n, e + 1);
        }
        return n;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> fac;
    for (int _ = 0; _ < n; _++) {
        int x, k;
        cin >> x >> k;
        fac.emplace_back(x, k);
    }
    ll c = divs_cnt(fac);
    ll s = divs_sum(fac);
    ll p = divs_prd(fac);
    cout << c << ' ' << s << ' ' << p << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}