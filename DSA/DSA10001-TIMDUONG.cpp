

/*

    Cho một bảng S[][] kích thước N x M, bao gồm các ô trống, 
    
    các vật cản. Ban đầu bạn ở vị trí S. Nhiệm vụ của bạn là hãy 
    
    di chuyển tới vị trí T, sao cho số lần đổi hướng không quá hai lần.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test bắt đầu bởi hai số nguyên N và M (1 ≤ N, M ≤ 500).

    N dòng tiếp theo, mỗi dòng gồm M kí tự mô tả bảng S. 
    
    Trong đó: ‘.’ là một ô trống, ‘*’ là vật cản, ‘S’ là vị trí 
    
    xuất phát và ‘T’ là vị trí đích. (Chỉ có một vị trí S và T duy nhất).

Output: 

    Với mỗi test, in ra “YES” nếu tìm được đường đi, 
    
    ra in “NO” trong trường hợp ngược lại.

Ví dụ:

Input               Output

2

5 5                 YES

..S..

****.

T....

****.

.....

5 5                 NO

S....

****.

.....

.****

..T..

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, m, ok, s1, s2, t1, t2;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
char a[1005][1005];

void inp()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S')
            {
                s1 = i;
                s2 = j;
            }
            else if (a[i][j] == 'T')
                t1 = i, t2 = j, a[i][j] = '.';
        }
    }
    ok = 0;
}
void dfs(int i, int j, int cnt, int huong)
{
    a[i][j] = '*';
    if (i == t1 && j == t2 && cnt <= 2)
        ok = 1;
    for (int k = 0; k < 4; k++)
    {
        int I = i + dx[k], J = j + dy[k];
        if (I >= 1 && J >= 1 && I <= n && J <= m && a[I][J] == '.')
        {
            if (k == huong || huong == -1)
                dfs(I, J, cnt, k);
            else if ((k != huong && huong != -1) && cnt + 1 <= 2)
                dfs(I, J, cnt + 1, k);
        }
    }
}
void solve()
{
    inp();
    dfs(s1, s2, 0, -1);
    if (ok)
        cout << "YES";
    else
        cout << "NO";
    cout << "\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}