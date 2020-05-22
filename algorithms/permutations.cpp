#include<bits/stdc++.h>
using namespace std;

int n = 3;
vector<int> p;
bool chosen[5];

void search() {
    if ((int)p.size() == n) {
        cout << '{';
        for (int i = 0; i < (int)p.size(); i++) {
            if (i) cout << ", ";
            cout << p[i];
        }
        cout << "}\n";
    } else {
        for (int i = 1; i <= n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            p.push_back(i);
            search();
            chosen[i] = false;
            p.pop_back();
        }
    }
}

void solve() {
    search();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
