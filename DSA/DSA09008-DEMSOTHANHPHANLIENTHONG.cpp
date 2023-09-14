
/*

    Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
    
    Hãy tìm số thành phần liên thông của đồ thị.

Input:

    Dòng đầu tiên đưa vào T là số lượng bộ test.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số 
    
    |V|, |E| tương ứng với số đỉnh và số cạnh; 
    
    Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.

    T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

    Đưa ra số thành phần liên thông của đồ thị.
Ví dụ:

Input:                          Output:

1

5 6 

1 2 1 3 2 3 3 4 3 5 4 5         1

*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

vector<int> a[1005]; // danh sach ke : O(V + E)
bool vs[1005];

inline void BFS(int u)
{
    queue<int> Q;
    Q.push(u);
    vs[u] = true;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (auto v : a[u])
        {
            if (!vs[v])
            {
                Q.push(v);
                vs[v] = true;
            }
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
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x].pb(y);
            a[y].pb(x);
        }
        for (int i = 1; i <= n; i++)
        {
            sort(all(a[i]));
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vs[i])
            {
                ++ans;
                BFS(i);
            }
        }
        cout << ans << "\n";
        for (int i = 1; i <= n; i++)
        {
            a[i].clear();
            vs[i] = false;
        }
    }
}