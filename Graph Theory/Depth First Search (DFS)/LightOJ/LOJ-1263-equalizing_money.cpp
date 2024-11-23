//https://lightoj.com/problem/equalizing-money
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 10000+5;

vector<int> g[N];
bool vis[N];
int money[N];
int moneysum = 0;
int components = 0;

void dfs(int u) {
    vis[u] = true;
    components++;
    moneysum += money[u];
    for (auto v: g[u]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> money[i];
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        g[i].clear();
    }
    while(m--) {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool ans = true;
    set<int> individual_money;
    for (int i = 1; i <= n; i++) {
        if(!vis[i]) {
            moneysum = components = 0;
            dfs(i);
            if (moneysum % components != 0) {
                ans = false;
                break;
            }
            else
                individual_money.insert(moneysum/components);
        }
    }
    if (ans && individual_money.size() == 1) cout << "Yes\n";
    else cout << "No\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    int q = 0;
    cin >> t; q = 1;
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

