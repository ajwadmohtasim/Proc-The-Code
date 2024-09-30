//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

vector<ll> tree(4*N);
vector<ll> a(N);

void build(int node, int b, int e)
{
    if (b == e) {
        tree[node] = a[b];
        return;
    }
    int l = 2*node, r = 2*node + 1;
    int mid = (b + e) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[node] = tree[l] + tree[r];
}

long long query(int node, int b, int e, int i, int j)
{
    /*
            i <------------> j
        b,e                     b,e
                    b,e
    */ 
    if (b > j or e < i) return 0;
    if (b >= i and e <= j) return tree[node];
    int l = 2*node, r = 2*node + 1;
    int mid = (b + e) / 2;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}

void update(int node, int b, int e, int i, int x)
{
    if (b > i or e < i) return;
    if (b == e and b == i) {
        tree[node] = x;
        return;
    }
    int l = 2*node, r = 2*node + 1;
    int mid = (b + e) / 2;
    update(l, b, mid, i, x);
    update(r, mid + 1, e, i, x);
    tree[node] = tree[l] + tree[r];
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
            update(1, 1, n, ++i, v);
        }
        if (k == 2) {
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, ++l, r) << "\n";            
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

