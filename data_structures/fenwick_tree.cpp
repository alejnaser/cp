#include<bits/stdc++.h>
using namespace std;

#define mfor(i,a,b) for(int i=(a);i<(b);i++)

//1-indexed
#define N 10
int ft[N+1];
void ft_init(int* A){
    mfor(i,1,N+1)
        ft[i]=A[i];
    mfor(i,1,N+1){
        int j=i+(i&-i);
        if(j<=N)ft[j]+=ft[i];
    }
}
int ft_sum(int i){
    int s=0;
    while(i){
        s+=ft[i];
        i&=~(i&-i);
    }
    return s;
}
void ft_add(int i, int x){
    while(i<=N){
        ft[i]+=x;
        i+=i&-i;
    }
}
int ft_query(int l, int r){
    if(r<l)return 0;
    return ft_sum(r)-ft_sum(l-1);
}

void solve(){
    int A[]={0,9,6,2,1,7,10,8,3,5,4};//1-indexed
    ft_init(A);
    cout<<ft_query(1,5)<<'\n';
    cout<<ft_query(6,10)<<'\n';
    cout<<ft_query(1,10)<<'\n';
    ft_add(8,5);
    cout<<ft_query(1,5)<<'\n';
    cout<<ft_query(6,10)<<'\n';
    cout<<ft_query(1,10)<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
