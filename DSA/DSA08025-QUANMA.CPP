
/*

    Cho một quân mã trên bàn cờ vua tại vị trí ST. Nhiệm vụ của bạn

    là hãy tìm số bước di chuyển ít nhất để đưa quân mã tới vị trí EN.

    c:\Users\ADMIN\Downloads\download (2).png

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm 2 xâu dạng “xy” và “uv”, trong đó x, y

    là kí tự trong “abcdefgh” còn

    y, v là số thuộc 1, 2, 3, 4, 5, 6, 7, 8.

Output:

    Với mỗi test, in ra đáp án tìm được trên một dòng.

Ví dụ:



Input               Output

8

e2 e4               2

a1 b2               4

b2 c3               2

a1 h8               6

a1 h7               5

h8 a1               6

b1 c3               1

f6 f6               0

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define ii pair<int, int>

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

bool vis[1005][1005];
int u, v, s, t;
int dist[1005][1005];

bool check(int i, int j)
{
    return (i >= 0 && i < 8) && (j >= 0 && j < 8);
}

int bfs(int i, int j)
{
    queue<ii> Q;
    vis[i][j] = 1;
    Q.push({i, j});
    int step = 0;
    while (!Q.empty())
    {
        int tmp = Q.size();
        while (tmp--)
        {
            ii top = Q.front();
            Q.pop();
            int x = top.fi, y = top.se;
            if (x == s && y == t)
            {
                return step;
            }
            else
            {
                for (int k = 0; k < 8; k++)
                {
                    int I1 = x + dx[k];
                    int J1 = y + dy[k];
                    if (check(I1, J1) && vis[I1][J1] == 0)
                    {
                        vis[I1][J1] = 1;
                        Q.push({I1, J1});
                    }
                }
            }
        }
        ++step;
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T-- > 0)
    {
        string a, b;
        cin >> a >> b;
        memset(dist, 0, sizeof(dist));
        memset(vis, 0, sizeof(vis));

        u = a[1] - '0' - 1;
        v = a[0] - 'a';
        s = b[1] - '0' - 1;
        t = b[0] - 'a';

        // cout << u << " " << v << "\n";
        // cout << s << " " << t << "\n";
        cout << bfs(u, v) << "\n";
    }
}