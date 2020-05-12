#include<bits/stdc++.h>
using namespace std;

vector<int> to_big_int(int n){
    vector<int>ans;
    if(n==0)ans={0};
    else while(n){ans.push_back(n%10);n/=10;}
    return ans;
}
void print_big_int(vector<int>a){
    for(int i=(int)a.size()-1;i>=0;i--)cout<<a[i];
    cout<<'\n';
}
vector<int> prod_big_int(vector<int>a,vector<int>b){
    int c=0,size=(int)a.size()+(int)b.size()-1;
    vector<int>ans(size,0);
    for(int i=0;i<(int)a.size();i++)
        for(int j=0;j<(int)b.size();j++)
            ans[i+j]+=a[i]*b[j];
    for(int i=0;i<size;i++)
        {ans[i]+=c;c=ans[i]/10;ans[i]%=10;}
    if(c)ans.push_back(c);
    return ans;
}
vector<int> sum_big_int(vector<int> a, vector<int> b) {
    int c=0,size=max((int)a.size(),(int)b.size());
    vector<int>ans(size,0);
    for(int i=0;i<size;i++){
        ans[i]=c;
        if(i<(int)a.size())ans[i]+=a[i];
        if(i<(int)b.size())ans[i]+=b[i];
        c=ans[i]/10;ans[i]%=10;
    }
    if(c)ans.push_back(c);
    return ans;
}
vector<int> exp_big_int(vector<int>a,int e){
    if(e==0)return to_big_int(1);
    if(e%2)return prod_big_int(a,exp_big_int(a,e-1));
    else{vector<int>t=exp_big_int(a,e/2);return prod_big_int(t,t);}
}

void solve() {
    vector<int> ans = to_big_int(0);

    ans = sum_big_int(ans, exp_big_int(to_big_int(2), 1819));
    ans = sum_big_int(ans, exp_big_int(to_big_int(2), 1278));

    print_big_int(ans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}