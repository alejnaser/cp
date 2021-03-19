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

// complexity: O(sqrt n)

vector<int> divisors(int n) {
    vector<int> ds;
    for (int d = 1; d * d <= n; d++)
        if (n % d == 0) {
            ds.push_back(d);
            if (n / d != d)
                ds.push_back(n / d);
        }
    return ds;
}

void solve() {
    for (auto [p, e] : factorize(840))
        cout << p << "^" << e << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sieve();
    solve();
    return 0;
}
