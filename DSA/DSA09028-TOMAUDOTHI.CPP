


/*

    Một trong những bài toán kinh điển của lý thuyết đồ thị là bài toán 
    
    Tô màu đồ thị. Bài toán được phát biểu như sau: Cho đồ thị vô hướng 
    
    G =<V, E> được biểu diễn dưới dạng danh sách cạnh và số M. 
    
    Nhiệm vụ của bạn là kiểm tra xem đồ thị có thể tô màu các đỉnh bằng nhiều nhất 
    
    M màu sao cho hai đỉnh kề nhau đều có màu khác nhau hay không?

    C:\Users\ADMIN\Downloads\mcolor.png

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào 
    
    ba số V, E, M tương ứng với số đỉnh, số cạnh và số màu; 
    
    phần thứ hai đưa vào các cạnh của đồ thị.

    T, V, E, M thỏa mãn ràng buộc: 1≤T ≤100; 1≤V≤10; 1≤ E ≤N(N-1), 1≤V≤N.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input                       Output

2
4  5  3                     YES
1 2
2 3
3 4
4 1
1 3

3 3 2                       NO
1 2
2 3
1 3

*/



#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x, end()

int V, E, M;
vector<int> adj[1005];
int color[1005];

bool noColor(int u, int c)
{
    for (auto x : adj[u])
    {
        if (color[x] == c)
        {
            return false;
        }
    }
    return true;
}

bool isColor(int u)
{

    if (u == V + 1)
    {
        return true;
    }

    for (int c = 1; c <= M; c++)
    {
        if (noColor(u, c))
        {
            color[u] = c;

            bool full = isColor(u + 1);
            if (full)
            {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin >> V >> E >> M;
    for (int i = 1; i <= V; i++)
    {
        adj[i].clear();
        color[i] = 0;
    }
    while (E--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if (isColor(1))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}