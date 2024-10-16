//https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU {
    vector<int> par, rnk, sz;
    int c;
    DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
        for (int i = 1; i <= n; ++i) par[i] = i;
    }
    int find(int i) {
        return (par[i] == i ? i : (par[i] = find(par[i])));
    }
    bool same(int i, int j) {
        return find(i) == find(j);
    }
    int get_size(int i) {
        return sz[find(i)];
    }
    int count() {
        return c;  
    }
    int merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return -1;
        else --c;
        if (rnk[i] > rnk[j]) swap(i, j);
        par[i] = j;
        sz[j] += sz[i];
        if (rnk[i] == rnk[j]) rnk[j]++;
        return j;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    struct DSU d1 = {n};
    while (m--) {
        string s; cin >> s;
        int u, v; cin >> u >> v;
        if (s == "union") {
            d1.merge(u, v);
        }
        if (s == "get") {
            if (d1.same(u,v)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    int q = 0;
    // cin >> t; q = 0;
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
 