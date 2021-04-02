#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
ll mulmod(ll a, ll b, ll m) {
    ll r=a*b-(ll)((long double)a*b/m+.5)*m;
    return r<0?r+m:r;
}
ll expmod(ll b, ll e, ll m){
    if(!e)return 1;
    ll q=expmod(b,e/2,m);q=mulmod(q,q,m);
    return e&1?mulmod(b,q,m):q;
}
bool is_prime_prob(ll n, int a){
    if(n==a)return true;
    ll s=0,d=n-1;
    while(d%2==0)s++,d/=2;
    ll x=expmod(a,d,n);
    if((x==1)||(x+1==n))return true;
    fore(_,0,s-1){
        x=mulmod(x,x,n);
        if(x==1)return false;
        if(x+1==n)return true;
    }
    return false;
}
bool rabin(ll n){ // true iff n is prime
    if(n==1)return false;
    int ar[]={2,3,5,7,11,13,17,19,23};
    fore(i,0,9)if(!is_prime_prob(n,ar[i]))return false;
    return true;
}
ll rho(ll n){
    if(!(n&1))return 2;
    ll x=2,y=2,d=1;
    ll c=rand()%n+1;
    while(d==1){
        x=(mulmod(x,x,n)+c)%n;
        y=(mulmod(y,y,n)+c)%n;
        y=(mulmod(y,y,n)+c)%n;
        if(x>=y)d=gcd(x-y,n);
        else d=gcd(y-x,n);
    }
    return d==n?rho(n):d;
}

void fuckt(ll n, map<ll,int>& f){ //O (lg n)^3
    if(n==1)return;
    if(rabin(n)){f[n]++;return;}
    ll q=rho(n);
    fuckt(q,f);fuckt(n/q,f);
}

map<ll,int> factorize(ll n) {
    map<ll, int> f;
    fuckt(n,f);
    return f;
}

ll pow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b & 1) {
        return a * pow(a, b - 1);
    } else {
        ll tmp = pow(a, b / 2);
        return tmp * tmp;
    }
}

vector<ll> divisors(ll n) {
    auto fac = factorize(n);
    vector<ll> ds = {1};
    for (auto p : fac) {
        int b = (int)ds.size();
        for (int i = 0; i < b; i++)
            for (ll e = 1; e <= p.snd; e++)
                ds.pb(ds[i] * pow(p.fst, e));
    }
    return ds;
}

bool is_prime(ll n) {
    if (n < 2)
        return 0;
    auto f = factorize(n);
    int cnt = 0, exp = 0;
    for (auto p : f) {
        cnt++;
        exp = max(exp, p.snd);
    }
    return cnt == 1 && exp == 1;
}

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    ll g = gcd(n * m, k);
    ll a = n * m / g, b = k / g;
    if (b > 2) {
        cout << "NO\n";
        return;
    }
    if (b == 1)
        a *= 2;
    vector<ll> divs = divisors(a);
    sort(divs.begin(), divs.end());
    for (ll x : divs) {
        if (x > n)
            break;
        ll y = a / x;
        if (y <= m) {
            cout << "YES\n";
            cout << "0 0\n";
            cout << x << " 0\n";
            cout << "0 " << y << '\n';
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
};
