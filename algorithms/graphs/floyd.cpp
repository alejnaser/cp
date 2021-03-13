#include<bits/stdc++.h>
using namespace std;

void solve() {
    int succ[7] = {0, 2, 3, 4, 5, 6, 4};
    int a, b, l, x = 1;
    a = succ[x];
    b = succ[succ[x]];
    while (a != b) {
        a = succ[a];
        b = succ[succ[b]];
    }
    a = x;
    while (a != b) {
        a = succ[a];
        b = succ[b];
    }
    cout << "First: " << a << '\n';
    b = succ[a];
    l = 1;
    while (a != b) {
        b = succ[b];
        l++;
    }
    cout << "Length: " << l << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

