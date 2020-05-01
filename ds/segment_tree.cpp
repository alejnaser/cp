#include<bits/stdc++.h>
using namespace std;

// Usage:
// SegmentTree st(A, op, neut);
// st.update(idx, val)
// st.query(left, right)

struct SegmentTree {
    vector<int> st, A;
    int n, neut, (*op)(int, int);

    int left(int p) {
        return p << 1;
    }

    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
        if (L == R) {
            st[p] = A[L]; // L if index is sought
        } else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = op(p1, p2);
        }
    }

    int query(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return neut;
        if (L >= i && R <= j) return st[p];
        int p1 = query(left(p), L, (L + R) / 2, i, j);
        int p2 = query(right(p), (L + R) / 2 + 1, R, i, j);
        return op(p1, p2);
    }

    void update(int p, int L, int R, int i, int k) {
        if (i > R || i < L) return;
        if (L == R) {
            st[p] = k;
        } else {
            int m = (L + R) / 2;
            if (i <= m) update(left(p), L, m, i, k);
            else update(right(p), m + 1, R, i, k);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = op(p1, p2);
        }
    }

    SegmentTree(vector<int> _A, int (*_op)(int, int), const int _neut) {
        A = _A;
        op = _op;
        neut = _neut;
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int query(int i, int j) {
        return query(1, 0, n - 1, i, j);
    }

    void update(int i, int k) {
        return update(1, 0, n - 1, i, k);
    }
};

int sum(int a, int b) {
    return a + b;
}

void solve(){
    vector<int> A = {9, 6, 2, 1, 7, 10, 8, 3, 5, 4};
    SegmentTree st(A, sum, 0);

    cout << st.query(0, 4) << '\n';
    cout << st.query(5, 9) << '\n';
    cout << st.query(0, 9) << '\n';

    st.update(2, 4);
    st.update(7, 5);

    cout << st.query(0, 4) << '\n';
    cout << st.query(5, 9) << '\n';
    cout << st.query(0, 9) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
