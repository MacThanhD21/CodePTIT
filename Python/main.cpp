
// Đỉnh Thắt

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check(int n, int k, int u, int v, vector<vector<int>>& ke) {
    queue<int> q;
    vector<int> a(n + 1, 0);
    q.push(u);
    a[u] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == v) return false;
        for (int i : ke[x]) {
            if (a[i] == 0 && i != k) {
                q.push(i);
                a[i] = 1;
            }
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, m, u, v;
        cin >> n >> m >> u >> v;

        vector<vector<int>> ke(n + 1);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i != u && i != v) {
                if (check(n, i, u, v, ke)) {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
