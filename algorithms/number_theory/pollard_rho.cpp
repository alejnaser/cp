#include <bits/stdc++.h>
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

map<ll,int> factorizar(ll n) {
	map<ll, int> f;
	fuckt(n,f);
	return f;
}

bool is_prime(ll n) {
    if (n < 2)
        return 0;
    auto f = factorizar(n);
    int cnt = 0, exp = 0;
    for (auto p : f) {
        cnt++;
        exp = max(exp, p.snd);
    }
    return cnt == 1 && exp == 1;
}

void solve() {
    ll n; cin >> n;

    map<int, int> mp;
    for (int i = 0; i <= 9; i++)
        mp[i] = i;
    mp[6] = 9; mp[9] = 6;

    if (!is_prime(n)) {
        cout << "no\n";
        return;
    }

    ll d, m = 0;
    while (n) {
        d = n % 10;
        if (d == 3 || d == 4 || d == 7) {
            cout << "no\n";
            return;
        }
        m = 10 * m + mp[d];
        n /= 10;
    }

    cout << (is_prime(m) ? "yes" : "no") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}