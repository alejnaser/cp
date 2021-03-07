#include<bits/stdc++.h>
using namespace std;

int kmp(string t, string p, bool b) {
    int m = (int)p.size();
    vector<int> v(100005);
    int i = 0, j = -1; v[0] = -1;
    while (i < m) {
        while (j >= 0 && p[i] != p[j]) j = v[j];
        i++; j++;
        v[i] = j;
    }
    i = 0, j = 0;
    int n = (int)t.size();
    while (i < n) {
        while (j >= 0 && t[i] != p[j]) j = v[j];
        i++; j++;
        if (b && j == m)
            return 1;
        if (!b && i == n)
            return j;
    }
    return 0;
}

void solve() {
    vector<string> v(3);
    for (int i = 0; i < 3; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 3 * 100005;
    do {
        string a = v[0], b = v[1], c = v[2];
        if (!kmp(a, b, 1))
            a += b.substr(kmp(a, b, 0));
        if (!kmp(a, c, 1))
            a += c.substr(kmp(a, c, 0));
        ans = min(ans, (int)a.size());
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}