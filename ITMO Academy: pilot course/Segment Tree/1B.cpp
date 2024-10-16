//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5, inf = 1e9 + 9;
int a[N];
vector<int> t(N*4, INT_MAX);

void build(int node, int b, int e)
{
    if (b == e) {
        t[node] = a[b];
        return;
    }
    int mid = (b + e) >> 1, l = 2*node, r = 2*node + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[node] = min(t[l], t[r]);
}

void upd(int node, int b, int e, int i, int v)
{
    if (b > i or e < i ) return;
    if (b == e and b == i) {
        t[node] = v;
        return;
    } 
    int mid = (b + e) >> 1, l = 2*node, r = 2*node + 1;
    upd(l, b, mid, i, v);
    upd(r, mid + 1, e, i, v);
    t[node] = min(t[l], t[r]);
}

int query(int node, int b, int e, int i, int j)
{
    if (b > j or e < i) return inf;
    if (b >= i and e <= j) {
        return t[node]; 
    } 
    int mid = (b + e) >> 1, l = 2*node, r = 2*node + 1;
    return min(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(m--)
    {
        int k; cin >> k;
        if (k == 1) {
            int i, v; cin >> i >> v;
            upd(1, 1, n, ++i, v);
        }
        if (k == 2) {
            int l, r; cin >> l >> r;
            ++l;
            cout << query(1, 1, n, l, r) << "\n";
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

