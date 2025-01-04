//https://cses.fi/problemset/task/1676
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll find(ll x, vector<ll> &parent) {
    return ((parent[x] != x) ? (parent[x] = find(parent[x], parent)) : x);
}
void unions(ll a, ll b, ll &components, ll &maxsize, vector<ll> &size, vector<ll> &parent) {
    ll x = find(a, parent);
    ll y = find(b, parent);
    if (x != y){
        components--;
        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        maxsize = max(maxsize, size[x]);
    }   
}
void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> parent(n+1, 0);
    for (ll i = 1; i <= n; i++) {
        parent[i] = i;
    }
    ll components = n;
    ll maxsize = 1;
    vector<ll> size(n+1, 1);
    for (int i = 1; i <= m; i++) {
        ll a, b; cin >> a >> b;
        unions(a, b, components, maxsize, size, parent);
        cout << components << " " << maxsize << "\n";

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

