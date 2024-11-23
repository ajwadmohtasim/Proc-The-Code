//https://vjudge.net/problem/UVA-572
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 105;

string s[N];
bool vis[N][N];
int n, m;
int chki[] = {+1, +1, 0, -1, -1, -1, 0, +1};
int chkj[] = {0, -1, -1, -1, 0, +1, +1, +1};


void dfs(int i, int j) {
    vis[i][j] = true;
    for (int k = 0; k < 8; k++) {
        int x = i + chki[k];
        int y = j + chkj[k];
        if ((x < n) and (x >= 0) and (y < m) and (y >= 0)) {
            if (!vis[x][y] and s[x][y] == '@')
                dfs(x, y);
        }
    }
}

void solve() {
    while (cin >> n >> m and n and m) {
        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) vis[i][j] = false;
        int components = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == '@' && !vis[i][j]) {
                    dfs(i , j);
                    components++;
                }
            }
        }
        cout << components << "\n";    
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

