//https://lightoj.com/problem/curious-robin-hood

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5, inf = 1e9 + 9;
int a[N];
int returnmoney = 0;
vector<int> t(N*4);

void build(int node, int b, int e)
{
    if (b == e) {
        t[node] = a[b];
        return;
    }
    int mid = (b + e) >> 1, l = 2*node, r = 2*node + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[node] = t[l] + t[r];
}

void upd(int node, int b, int e, int i, int v, int mode)
{

    if (b > i or e < i ) return;
    if (b == e and b == i) {
        if (mode == 1) {
            returnmoney = t[node];
            t[node] = v;
        }
        if (mode == 2) t[node] += v;
        return;
    } 
    int mid = (b + e) >> 1, l = 2*node, r = 2*node + 1;
    upd(l, b, mid, i, v, mode);
    upd(r, mid + 1, e, i, v, mode);
    t[node] = t[l] + t[r];
}

int query(int node, int b, int e, int i, int j)
{
    if (b > j or e < i) return 0;
    if (b >= i and e <= j) {
        return t[node]; 
    } 
    int mid = (b + e) >> 1, l = 2*node, r = 2*node + 1;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
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
            int i; cin >> i;
            upd(1, 1, n, ++i, 0, 1);
            cout << returnmoney << "\n";
        }
        if (k == 2) {
            int i, v; cin >> i >> v;
            upd(1, 1, n, ++i, v, 2);
        }
        if (k == 3) {
            int l, r; cin >> l >> r;
            ++l, ++r;
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
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
            cout << "Case " << q << ":\n";
            q++;
        }
        solve();
    }
    return 0;
}

