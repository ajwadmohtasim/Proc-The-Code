//https://codeforces.com/contest/24/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 105;

vector<pair<int,int>> g[N];
int vis[N];
int cost = 0;

void dfs(int u, int p = 0) {
    vis[u] = true;
    for (auto [v, w] : g[u]) {
        if (!vis[v]) {
            cost += w;
            dfs(v, u);
        }
        else if (v == 1 and p!= 1) {
            cost += w;
        }
    }
}

void solve() {
    int n; cin >> n;
    int totalcost = 0;
    for (int i = 1; i <= n; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, 0});
        g[v].push_back({u, w});
        totalcost += w;
    }
    dfs(1);
    cout << min(cost, totalcost-cost);
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