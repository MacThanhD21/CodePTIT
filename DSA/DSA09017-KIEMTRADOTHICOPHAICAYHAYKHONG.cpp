
/*

    Một đồ thị N đỉnh là một cây, nếu như nó có đúng N-1 cạnh và giữa 
    
    2 đỉnh bất kì, chỉ tồn tại duy nhất 1 đường đi giữa chúng.

    Cho một đồ thị N đỉnh và N-1 cạnh, hãy kiểm tra đồ thị 
    
    đã cho có phải là một cây hay không?

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test bắt đầu bởi số nguyên N (1 ≤ N ≤ 1000).

    N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v 
    
    cho biết có cạnh nối giữa đỉnh u và v.

Output: 

    Với mỗi test, in ra “YES” nếu đồ thị đã cho là một cây, 
    
    in ra “NO” trong trường hợp ngược lại.

Ví dụ:

Input                   Output

2

4                       YES

1 2

1 3

2 4

4                       NO

1 2

1 3

2 3

*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1005;

int n;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

bool is_tree()
{
    memset(visited, false, sizeof(visited));
    dfs(1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            cnt++; // đếm số lượng đỉnh đã duyệt
        }
    }
    if (cnt != n)
    { // đồ thị không liên thông
        return false;
    }
    memset(visited, false, sizeof(visited));
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> n;
        m = n - 1;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (is_tree())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }
    }
}

// - Cách 2 
/*
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1005;

int n;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs1(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs1(v);
        }
    }
}

bool dfs2(int u, int par){
    visited[u] = true;
    for(auto x : adj[u]){
        if(!visited[x]){
            int check = dfs2(x, u);
            if(check)
                return true;
        }
        else if(x != par){
            return true;
        }
    }
    return false;
}

bool is_tree()
{
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++; // đếm số lượng đỉnh đã duyệt
            dfs1(i);
        }
    }
    // đồ thị không liên thông
    if (cnt != 1)
    { 
        return false;
    }
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if(dfs2(i, -1)){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> n;
        m = n - 1;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (is_tree())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }
    }
}
*/