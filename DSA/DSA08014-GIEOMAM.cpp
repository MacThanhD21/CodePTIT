

/*

    Trên một giá có kích thước R x C (R hàng, C cột), một số

    hạt mầm đã được tra vào các ô. Một số hạt mầm được bón thêm

    chất dinh dưỡng, nên đã nảy mầm sớm thành cây non.

    Mỗi ngày, các cây non sẽ lan truyền chất dinh dưỡng của nó

    cho các mầm ở ô xung quanh (trái, trên, phải, dưới), làm cho

    các hạt mầm này phát triển thành cây non. Tuy nhiên, có thể

    có một số hạt mầm được gieo ở vị trí lẻ loi, do không nhận

    được chất dinh dưỡng nên không thể nảy mầm.

    Các bạn hãy xác định xem cần ít nhất bao nhiêu

    ngày để tất cả các hạt đều mầm?

Input:

    Dòng đầu ghi số bộ test (không quá 10). Mỗi bộ test gồm:

    Dòng đầu tiên gồm 2 số nguyên R và C (1 ≤ R, C ≤ 500).

    R dòng tiếp theo, mỗi dòng gồm C số nguyên A[i][j].

    A[i][j] = 0, ô (i, j) là ô trống.

    A[i][j] = 1, ô (i, j) là hạt chưa nảy mầm.

    A[i][j] = 2, ô (i, j) là cây non.

Output:

    Với mỗi test in ra thời gian ngắn nhất để tất cả

    các hạt đều nảy mầm. Nếu có hạt nào chưa nảy mầm, in ra -1.

Ví dụ:

Input                   Output

2

3 5                     2

2 1 0 2 1

1 0 1 2 1

1 0 0 2 1

3 5                     -1

2 1 0 2 1

0 0 1 2 1

1 0 0 2 1

*/

#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define fi first
#define se second
#define mp make_pair

int n, m;
int a[505][505];
bool used[505][505];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            used[i][j] = false;
        }
    }
    queue<ii> Q;
    int coun = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
            {
                continue;
            }
            else if (a[i][j] == 1)
            {
                ++coun;
            }
            else
            {
                ii begin = mp(i, j);
                Q.push(begin);
            }
        }
    }
    int ans = 0; 
    while (!Q.empty())
    {
        int tmp = Q.size();
        bool ok = false; // DANH dau ngay hiện tại có thể nảy mầm được hay không?
        while (tmp--)
        {
            auto top = Q.front();
            Q.pop();
            int i = top.fi, j = top.se;
            for (int k = 0; k < 4; k++)
            {
                ii v = mp(i + dx[k], j + dy[k]);
                int I = v.fi, J = v.se;
                if (I < 0 || I >= n || J < 0 || J >= m)
                    continue;
                if (a[I][J] == 0 || a[I][J] == 2)
                    continue;
                if (used[I][J])
                    continue;

                used[I][J] = true;
                a[I][J] = 2;
                Q.push(v);
                --coun;
                ok = true;
            }
        }

        if (ok)
            ++ans;
    }
    if (coun != 0)
        cout << "-1\n";
    else
        cout << ans << "\n";
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