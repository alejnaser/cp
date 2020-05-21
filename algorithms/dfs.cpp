#include<bits/stdc++.h>
using namespace std;

vector<int> dfs_num;
vector<int> adj[100005];

#define VISITED 1
#define UNVISITED -1

#define PB push_back

void dfs(int u) {
    printf(" %d", u);
    dfs_num[u] = VISITED;
    for (int j = 0; j < (int)adj[u].size(); j++) {
        int v = adj[u][j];
        if (dfs_num[v] == UNVISITED)
            dfs(v);
    }
}

void solve() {
    int N = 9, numCC = 0;

    adj[0] = {1};
    adj[1] = {2, 3};
    adj[3] = {2, 4};
    adj[4] = {3};
    adj[6] = {7, 8};
    adj[7] = {6};
    adj[8] = {6};

    dfs_num.assign(N, UNVISITED);
    for (int i = 0; i < N; i++)
        if (dfs_num[i] == UNVISITED)
            printf("CC %d:", ++numCC), dfs(i), printf("\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
