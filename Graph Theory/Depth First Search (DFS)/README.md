
A basic DFS implementation : 
```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for (auto v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    int q = 0;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```
