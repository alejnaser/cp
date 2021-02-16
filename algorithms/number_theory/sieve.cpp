#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define EB emplace_back
typedef long long ll;
vector<int> ps;
 
void sieve() {
    bitset<1000005> bs; bs.set();
    for (ll i = 2; i <= 1000000; i++) 
        if (bs[i]) {
            ps.push_back(i);
            for (ll j = i * i; j <= 1000000; j += i)
                bs[j] = 0;
        }
}

vector<pair<int, int>> factorize(ll n) {
    int e;
    vector<pair<int, int>> f;
    for (ll p : ps) {
        if (p * p > n) 
            break;
        e = 0;
        while (n % p == 0) 
            e++, n /= p;
        if (e) 
            f.EB(p, e);
    }
    if (n > 1) 
        f.EB(n, 1);
    return f;
}

void solve() {
    auto f = factorize(12345678);
    for (auto p : f)
        cout << p.F << "^" << p.S << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sieve();
    solve();
    return 0;
}
