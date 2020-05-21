#include<bits/stdc++.h>
using namespace std;

int n = 3;
vector<int> s;

void search(int k) {
    if (k == n + 1) {
        cout << '{';
        for (int i = 0; i < (int)s.size(); i++) {
            if (i) cout << ", ";
            cout << s[i];
        }
        cout << "}\n";
    } else {
        s.push_back(k);
        search(k + 1);
        s.pop_back();
        search(k + 1);
    }
}

void solve() {
    search(1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
