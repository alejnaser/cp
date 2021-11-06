#include<bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define mt make_tuple
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll gcd(ll a, ll b){while(b){ll t=a%b;a=b;b=t;}return a;}
pair<ll,ll> extendedEuclid (ll a, ll b){ //a * x + b * y = gcd(a,b)
    ll x,y;
    if (b==0) return {1,0};
    auto p=extendedEuclid(b,a%b);
    x=p.snd;
    y=p.fst-(a/b)*x;
    if(a*x+b*y==-gcd(a,b)) x=-x, y=-y;
    return {x,y};
}
pair<pair<ll,ll>,pair<ll,ll> > diophantine(ll a,ll b, ll r) {
    //a*x+b*y=r where r is multiple of gcd(a,b);
    ll d=gcd(a,b);
    a/=d; b/=d; r/=d;
    auto p = extendedEuclid(a,b);
    p.fst*=r; p.snd*=r;
    assert(a*p.fst+b*p.snd==r);
    return {p,{-b,a}}; // solutions: p+t*ans.snd
}

ll inv(ll a, ll m) {
    assert(gcd(a,m)==1);
    ll x = diophantine(a,m,1).fst.fst;
    return ((x%m)+m)%m;
}

#define mod(a,m) (((a)%m+m)%m)
pair<ll,ll> sol(tuple<ll,ll,ll> c){ //requires inv, diophantine
    ll a=get<0>(c), x1=get<1>(c), m=get<2>(c), d=gcd(a,m);
    if(d==1) return {mod(x1*inv(a,m),m), m};
    else return x1%d ? ii({-1LL,-1LL}) : sol(make_tuple(a/d,x1/d,m/d));
}
pair<ll,ll> crt(vector< tuple<ll,ll,ll> > cond) { // returns: (sol, lcm)
    ll x1=0,m1=1,x2,m2;
    for(auto t:cond){
        tie(x2,m2)=sol(t);
        if((x1-x2)%gcd(m1,m2))return {-1,-1};
        if(m1==m2)continue;
        ll k=diophantine(m2,-m1,x1-x2).fst.snd,l=m1*(m2/gcd(m1,m2));
        x1=mod((__int128)m1*k+x1,l);m1=l;
    }
    return sol(make_tuple(1,x1,m1));
} //cond[i]={ai,bi,mi} ai*xi=bi (mi); assumes lcm fits in ll

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<int> A(2 * max(m, n) + 1, -1), B(2 * max(m, n) + 1, -1);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        A[a] = i;
    }
    for (int i = 0; i < m; i++) {
        int b; cin >> b;
        B[b] = i;
    }
    vector<ll> V;
    for (int i = 1; i <= 2 * max(m, n); i++) {
        if (A[i] == -1 || B[i] == -1)
            continue;
        vector<tuple<ll,ll,ll> > cond = {mt(1,A[i],n),mt(1,B[i],m)};
        auto ans = crt(cond);
        if(ans.fst!=-1&&ans.snd!=-1)
            V.push_back(ans.fst);
    }
    sort(V.begin(), V.end());
    ll l = n * m / gcd(n, m);
    ll c = l - (ll)V.size();
    ll t = (k - 1) / c;
    ll ans = t * l;
    k -= t * c;
    assert (k <= c);
    for (int j = 0; j < (int)V.size(); j++) {
        if (k <= V[j] - j) {
           cout << ans + k + j << '\n';
           return;
        }
    }
    cout << ans + k + (int)V.size() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
};