//https://codeforces.com/contest/580/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+9;

vector<int> g[N];
int cats[N];
int vis[N];
int resturants = 0;
int cons_cats[N];
int n, m;

void dfs(int u, int p) {
    vis[u] = true;
    if (cats[u])
        cons_cats[u] = cons_cats[p] + 1;
    else
        cons_cats[u] = 0;
    if (cons_cats[u] > m) 
        return;
    bool is_leaf = true;
    for (auto v: g[u]) {
        if (!vis[v]) {
            dfs(v, u);
            is_leaf = false;
        }
    }
    if (is_leaf) resturants++;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i<=n; i++) cin >> cats[i];
    for (int i = 1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, cats[0]);
    cout << resturants;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    int q = 0;
    // cin >> t; q = 1;
    while (t--) {
        //custom test case:
        if (q) {
            cout << "Custom Test #" << q << ":\n";
            q++;
        }
        solve();
    }
    return 0;
}