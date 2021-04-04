#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define sieve_sz 20000005
vector<int> ps;
vector<int> sf;
bitset<sieve_sz + 1> bs;

// complexity: O(n log log n)

void sieve() {
    bs.set();
    sf.assign(sieve_sz + 1, 0);
    for (int p = 2; p <= sieve_sz; p++)
        if (bs[p]) {
            sf[p] = p;
            ps.push_back(p);
            for (ll n = (ll)p * p; n <= sieve_sz; n += p)
                if (bs[n]) {
                    bs[n] = 0;
                    sf[n] = p;
                }
        }
}

// complexity:
// O(sqrt n / log n) but
// O(log n) if n <= sieve_sz

vector<pair<ll, int>> factorize(ll n) {
    // n has O(log n) prime factors
    assert(1 <= n);
    assert(n <= sieve_sz * (ll)sieve_sz);
    vector<pair<ll, int>> f;
    if (n <= sieve_sz) {
        while (n != 1) {
            int e = 0;
            ll p = sf[n];
            while (n % p == 0) {
                e++;
                n /= p;
            }
            f.emplace_back(p, e);
        }
        return f;
    }
    for (ll p : ps) {
        if (p * p > n)
            break;
        if (n % p == 0) {
            int e = 0;
            while (n % p == 0) {
                e++;
                n /= p;
            }
            f.emplace_back(p, e);
        }
    }
    if (n > 1)
        f.emplace_back(n, 1);
    return f;
}

ll gcd(ll a, ll b) {
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// complexity: O(log e)

ll exp(ll a, int e) {
    ll r = 1;
    while (e) {
        if (e & 1)
            r *= a;
        a = a * a;
        e >>= 1;
    }
    return r;
}

// complexity: complexity of factorize + # of divisors of n

vector<ll> divisors(ll n) {
    auto fac = factorize(n);
    vector<ll> ds = {1};
    for (auto [p, a] : fac) {
        int b = (int)ds.size();
        for (int i = 0; i < b; i++)
            for (int e = 1; e <= a; e++)
                ds.push_back(ds[i] * exp(p, e));
    }
    return ds;
}

void solve() {
    for (auto [p, e] : factorize(840))
        cout << p << "^" << e << ' ';
    cout << '\n';
    auto ds = divisors(840);
    sort(ds.begin(), ds.end());
    for (int d : ds)
        cout << d << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sieve();
    solve();
    return 0;
}
