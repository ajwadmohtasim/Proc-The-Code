//https://codeforces.com/contest/2020/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll find(ll x, vector<ll> &parent) {
    return ((parent[x] != x) ? (parent[x] = find(parent[x], parent)) : x);
}

void unions(ll a, ll b, ll &components, vector<ll> &size, vector<ll> &parent) {
    ll x = find(a, parent);
    ll y = find(b, parent);
    if (x != y){
        components--;
        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }   
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> parent(n+1, 0);
    for (ll i = 1; i <= n; i++) {
        parent[i] = i;
    }
    ll components = n;
    vector<ll> size(n+1, 0);
    vector<vector<ll>> dp(n+1, vector<ll>(10+1, 0));
    for (ll i = 0; i < m; i++) {
        ll a, d, k; cin >> a >> d >> k;
        dp[a][d] = max(dp[a][d], k);
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= 10; j++) {
            if (dp[i][j]) {
                dp[i+j][j] = max(dp[i+j][j], dp[i][j] -1);
                unions(i+j, i, components, size, parent);
            }
        }
    }
    cout << components << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    int q = 0;
    cin >> t; q = 0;
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

