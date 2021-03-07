#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define SZ(x) int((x).size())
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

#define MAXN 1005
#define MAXM 1005

vector<int> g[MAXN],adj[MAXN],ts;
int n,m;
int mat[MAXM];bool vis[MAXN];
int match(int x){
	if(vis[x])return 0;
	vis[x]=true;
	for(int y:g[x])if(mat[y]<0||match(mat[y])){mat[y]=x;return 1;}
	return 0;
}
vector<pair<int,int> > max_matching(){
	vector<pair<int,int> > r;
	memset(mat,-1,sizeof(mat));
	fore(i,0,n)memset(vis,false,sizeof(vis)),match(i);
	fore(i,0,m)if(mat[i]>=0)r.pb({mat[i],i});
	return r;
}
void dfs(int v,bool f){
    vis[v]=true;
    for(int u:adj[v])
        if(!vis[u])
            dfs(u,f);
    if(f)
        ts.pb(v);
}
void solve() {
    cin>>n;m=n;
    fore(i,0,n){
        int k;cin>>k;
        while(k--){
            int j;cin>>j;
            g[i].pb(j);
        }
    }
    auto mm=max_matching();
    for(auto p:mm)
        adj[p.fst].pb(p.snd);
    memset(vis,false,sizeof(vis));
    fore(i,0,n)
        if(!vis[i])
            dfs(i,1);
    reverse(ts.begin(), ts.end());
    int ans=0;
    memset(vis,false,sizeof(vis));
    for(int v:ts)
        if(!vis[v]){
            ans++;
            dfs(v,0);
        }
    cout<<ans<<'\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}