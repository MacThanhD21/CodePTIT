
/*

    Cho một bản đồ kích thước N x M được mô tả bằng ma trận A[][].A[i][j] = 1 
    
    có nghĩa vị trí (i, j) là nổi trên biển. 2 vị trí (i, j) và (x, y) được coi 
    
    là liền nhau nếu như nó có chung đỉnh hoặc chung cạnh. Một hòn đảo là một tập hợp 
    
    các điểm (i, j) mà A[i][j] = 1 và có thể di chuyển giữa hai điểm bất kì trong đó.

    Nhiệm vụ của bạn là hãy đếm số lượng đảo xuất hiện trên bản đồ.

Input: 

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test bắt đầu bởi 2 số nguyên N và M (1 ≤ N, M ≤ 500).

    N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j].

Output:  

    Với mỗi test, in ra số lượng hòn đảo tìm được.

Ví dụ:

Input                   Output

1

5 5

1 1 0 0 0

0 1 0 0 1               5

1 0 0 1 1

0 0 0 0 0

1 0 1 0 1

*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1001][1001];
bool visited[1001][1001];
int cnt;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(int i, int j)
{
    visited[i][j] = true;
    for (int k = 0; k < 8; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 1 && !visited[i1][j1])
        {
            dfs(i1, j1);
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
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        }
        cnt = 0;
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 1 && !visited[i][j])
                {
                    dfs(i, j);
                    ++cnt;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}