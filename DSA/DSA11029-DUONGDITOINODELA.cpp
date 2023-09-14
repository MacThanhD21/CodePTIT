
/*

    Cho một cây có N node, gốc tại 1. Với mỗi node lá, bạn hãy in ra 
    
    đường đi từ node gốc tới nó.

    C:\Users\ADMIN\Downloads\download (16).png

Input:

    Dòng đầu tiên là số lượng bộ test T( T≤ 20).

    Mỗi test bắt đầu bằng số nguyên N (1 ≤ N ≤ 1000).

    N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v 
    
    cho biết node u nối với node v.

Output: 

    Với mỗi test, in ra K dòng, trong đó K là số lượng node lá. 
    
    Mỗi dòng là đường đi từ node gốc tới node lá X. Node lá nào có nhãn nhỏ hơn, in ra trước.

Ví dụ:

Input               Output

2

5

1 2                 1 3

1 3                 1 2 4

2 4                 1 2 5

2 5                 1 2 3 4

4

1 2

2 3

3 4

*/


#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

vector<int> adj[1005];
int par[1005];
bool vs[1005];

void dfs(int u)
{
    vs[u] = true;
    for (auto v : adj[u])
    {
        if (!vs[v])
        {
            par[v] = u;
            dfs(v);
        }
    }
}

void run()
{
    for (int i = 1; i <= 1005; i++)
    {
        adj[i].clear();
        vs[i] = false;
        par[i] = 0;
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    dfs(1);
    vector<int> path;
    for (int i = 1; i <= n; i++)
    {
        // cout << adj[i].size() << " ";

        if (adj[i].size() == 0)
        {
            int tmp = i;
            // cout << "hello\n";
            while (1 != tmp)
            {
                path.push_back(tmp);
                tmp = par[tmp];
            }
            path.push_back(1);
            reverse(path.begin(), path.end());
            for (int j = 0; j < path.size(); j++)
            {
                cout << path[j] << " ";
            }
            cout << "\n";
            path.clear();
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        run();
    }
}