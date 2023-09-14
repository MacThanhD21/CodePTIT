

/*

    Trường học X có N sinh viên, trong đó có M cặp là bạn bè của nhau. 
    
    Bạn của bạn cũng là bạn, tức là nếu A là bạn của B, B là bạn của 
    
    C thì A và C cũng là bạn bè của nhau.

    Các bạn hãy xác định xem số lượng sinh viên 
    
    nhiều nhất trong một nhóm bạn là bao nhiêu?

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test bắt đầu bởi 2 số nguyên N và M (N, M ≤ 100 000).

    M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v 
    
    (u #v) cho biết sinh viên u là bạn của sinh viên v.

Output: 

    Với mỗi test, in ra đáp án tìm được trên một dòng.

Ví dụ:

Input                   Output

2

3 2                     3

1 2

2 3

10 12                   7

1 2

3 1

3 4

5 4

3 5

4 6 

5 2

2 1

7 1

1 2

9 10

8 9

*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pb push_back
#define ms(a) memset(a, false, sizeof(a));

vector<int> adj[1005];
int n, m;
int par[100005], sz[100005];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}
int Find(int u)
{
    if (u == par[u])
        return u;
    return par[u] = Find(par[u]);
}

bool ComBine(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return false;
    if (sz[x] < sz[y])
        swap(x, y);
    sz[y] += sz[x];
    par[x] = y;
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        init();
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            ComBine(x, y);
        }
        cout << *(max_element(sz + 1, sz + n + 1)) << "\n";
    }
}