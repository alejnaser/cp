#include<bits/stdc++.h>
using namespace std;

#define mfor(i,a,b) for(int i=(a);i<(b);i++)

#define op min
// 2^P > N
int st[4][(int)1e1]; int P=4, N=1e1;
void st_init(int* A){
    mfor(i,0,N)st[0][i]=A[i];
    mfor(p,1,P)mfor(i,0,N)
        st[p][i]=op(st[p-1][i],st[p-1][i+(1<<(p-1))]);
}
int st_query(int l, int r){
    int k=31-__builtin_clz(r-l+1);
    return op(st[k][l],st[k][r-(1<<k)+1]);
}

void solve() {
    int A[]={9,6,2,1,7,10,8,3,5,4};
    st_init(A);
    cout<<st_query(0,4)<<'\n';
    cout<<st_query(5,9)<<'\n';
    cout<<st_query(0,9)<<'\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}