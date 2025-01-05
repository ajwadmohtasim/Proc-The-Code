//https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll find(ll x, vector<ll> &parent) {
    return ((parent[x] != x) ? (parent[x] = find(parent[x], parent)) : x);
}

void solve() {
    ll n; cin >> n;
    vector<ll> parent(n+1, 0);
    vector<ll> ans(n+1, 0);
    for (ll i = 1; i <= n; i++) {
        parent[i] = i;
        ans[i] = i;
    }
    for (ll i = 1; i <= n; i++) {
        ll p; cin >> p;
        ll x = find(parent[p], parent);
        ans[i] = x;
        parent[x] = find(parent[((x+1) % n == 0 ? n : (x+1) % n)], parent);
    }
    for (ll i = 1; i <= n; i++) 
        cout << ans[i] << " ";    
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

