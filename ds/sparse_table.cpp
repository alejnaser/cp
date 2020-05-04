#include<bits/stdc++.h>
using namespace std;

struct SparseTable{
    int (*op)(int,int);
    vector<vector<int>> st;
    int query(int l, int r){
        int k=31-__builtin_clz(r-l+1);
        return op(st[k][l],st[k][r-(1<<k)+1]);
    }
    SparseTable(vector<int>A,int(*_op)(int,int)){
        op=_op;int N=(int)A.size();int P=(int)log2(N)+1;
        st.assign(P,vector<int>(N));
        for(int i=0;i<N;i++)
            st[0][i]=A[i];
        for(int p=1;p<P;p++)
            for(int i=0;i+(1<<(p-1))<N;i++)
                st[p][i]=op(st[p-1][i],st[p-1][i+(1<<(p-1))]);
    }
};

int _min(int a, int b) {
    return min(a, b);
}

void solve() {
    vector<int> A = {9, 6, 2, 1, 7, 10, 8, 3, 5, 4};
    SparseTable st(A, _min);

    cout << st.query(0, 4) << '\n';
    cout << st.query(5, 9) << '\n';
    cout << st.query(0, 9) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}