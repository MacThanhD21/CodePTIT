

/*

    Tý đang xây dựng một mạng xã hội và mời các bạn của mình dùng thử. 
    
    Bạn của bạn cũng là bạn. Vì vậy, Tý muốn mạng xã hội của mình là hoàn hảo, 
    
    tức với mọi bộ ba X, Y, Z, nếu X kết bạn với Y, Y kết bạn với Z thì X và Z 
    
    cũng phải là bạn bè của nhau trên mạng xã hội.

    Các bạn hãy xác định xem mạng xã hội hiện tại của Tý có là 
    
    hoàn hảo hay không? Nếu có hãy in ra “YES”, “NO” trong trường hợp ngược lại.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test bắt đầu bởi 2 số nguyên N và M (N, M ≤ 100 000).

    M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v 
    
    (u #v) cho biết u và v là kết bạn với nhau trên mạng xã hội của Tý.

Output: 

    Với mỗi test, in ra đáp án tìm được trên một dòng.

Ví dụ:

Input                       Output

3

4 3                         YES

1 3

3 4

1 4

4 4                         NO

3 1

2 3

3 4

1 2

10 4                        YES

4 3

5 10

8 9

1 2

*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pb push_back
#define ms(a) memset(a, false, sizeof(a));

vector<int> adj[100005];
int n, m;

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
            adj[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        bool found = true;
        for (int u = 1; u <= n; u++)
        {
            for (auto v : adj[u])
            {
                if (adj[u].size() != adj[v].size())
                {
                    found = false;
                    break;
                }
            }
        }
        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}