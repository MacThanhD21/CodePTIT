

/*

    Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
    
    Hãy kiểm tra xem đồ thị có đường đi Euler hay chu trình Euler hay không?

    Đường đi Euler bắt đầu tại một đỉnh, và kết thúc tại một đỉnh khác.

    Chu trình Euler bắt đầu tại một đỉnh, và kết thúc chu trình tại chính đỉnh đó.

Input:

    Dòng đầu tiên đưa vào T là số lượng bộ test.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số 
    
    |V|, |E| tương ứng với số đỉnh,  số cạnh của đồ thị; 
    
    Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.

    T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

    Đưa ra 1, 2, 0 kết quả mỗi test theo từng dòng tương ứng 
    
    với đồ thị có đường đi Euler, chu trình Euler và trường hợp không tồn tại.

Ví dụ:

Input:                                                          Output:

2

6  10  

1 2 1 3 2 3 2 4 2 5 3 4 3 5 4 5 4 6 5 6                         2

6 9  

1  2 1  3 2  3 2  4 2  5 3  4 3  5 4  5 4  6                    1

*/


#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ii pair<int, int>

int n, m;
vector<int> adj_list[100005];
bool visited[100005];

void dfs(int u)
{
    visited[u] = true;
    for (auto v : adj_list[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

int getSize(int u)
{
    return adj_list[u].size();
}

int checkEulerPath()
{
    dfs(n);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            return 0;
        }
    }

    int odd = 0;
    for (int i = 1; i <= n; i++)
    {
        if (getSize(i) % 2 == 1)
            ++odd;
    }
    if (odd == 0)
        return 2;
    else if (odd == 2)
        return 1;
    else
        return 0;
}

int main()
{

    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            adj_list[i].clear();
            visited[i] = false;
        }
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj_list[x].pb(y);
            adj_list[y].pb(x);
        }
        cout << checkEulerPath() << "\n";
    }
}