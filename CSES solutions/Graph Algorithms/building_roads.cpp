//https://cses.fi/problemset/task/1666
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
 
vector<int> g[N];
bool vis[N];
int components = 0;
 
void dfs(int u) {
    vis[u] = true;
    for (auto v: g[u]) {
        if (!vis[v]) dfs(v);
    }
}
 
void solve() {
    int n, m; cin >> n >> m;
    while(m--) {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> road;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
            road.push_back(i);
            components++;
        }
    }
    cout << components - 1 << "\n";
    for (int i = 0; i < road.size()-1; i++) {
        cout << road[i] << " " << road[i+1] << "\n";
    }
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
            cout << "Case " << q << ": ";
            q++;
        }
        solve();
    }
    return 0;
}
