

/*

    Có K người (1 ≤ K ≤ 100) đứng tại vị trí nào đó trong N địa điểm 
    
    cho trước (1 ≤ N ≤ 1,000) được đánh số từ 1..N. Các điểm được nối 
    
    với nhau bởi M đoạn đường một chiều (1 ≤ M ≤ 10,000) 
    
    (không có đoạn đường nào nối một điểm với chính nó).

    Mọi người muốn cùng tụ họp tại một địa điểm nào đó. 
    
    Tuy nhiên, với các đường đi cho trước, chỉ có một số 
    
    địa điểm nào đó có thể được chọn là điểm họp mặt. 
    
    Cho trước K, N, M và vị trí ban đầu của K người cùng với M đường 
    
    đi một chiều, hãy xác định xem có bao nhiêu điểm có thể được chọn làm điểm họp mặt. 

Input

    Dòng 1: Ghi 3 số: K, N, và M 

    Dòng 2 đến K+1: dòng i+1 chứa một số nguyên trong khoảng 
    
    (1..N) cho biết địa điểm mà người thứ i đang đứng. 

    Dòng K+2 đến M+K+1: Mỗi dòng ghi một cặp số A và B mô tả 
    
    một đoạn đường đi một chiều từ A đến B (cả hai trong khoảng 1..N và A != B).

Output

    Số địa điểm có thể được chọn là điểm họp mặt.

Ví dụ

Input:                  Output:

2 4 4

2                       2

3

1 2

1 4

2 3

3 4

Giải thích Ví dụ: có thể họp mặt tại điểm 3 và điểm 4.
*/

#include <bits/stdc++.h>

using namespace std;

int k, n, m;
int pos;
vector<int> adj[1005];
bool used[1005];
int fre[1005];

vector<int> position;

void dfs(int u)
{
    used[u] = true;
    for (auto x : adj[u])
    {
        if (!used[x])
        {
            dfs(x);
        }
    }
}

void solve()
{
    cin >> k >> n >> m;
    int tmp = k;
    while (k--)
    {
        cin >> pos;
        position.push_back(pos);
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    int ans = 0;
    int pos;
    for (auto x : position)
    {
        // cout << x << " ";
        memset(used, false, sizeof(used));
        dfs(x);
        for (int i = 1; i <= n; i++)
        {
            if (used[i])
            {
                fre[i]++;
                cout << fre[i] << " " << i << "\n";
            }
            if (fre[i] == tmp)
                ++ans;
        }
    }
    cout << ans << "\n";
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}