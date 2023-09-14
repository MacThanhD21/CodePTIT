
/*

    Trên cánh đồng kích thước N x N có K chú cừu. Người nông dân sợ 
    
    các chú cừu đi lạc nên đã làm một số rào chắn giữa các khu vực. 
    
    Các chú cừu chỉ có thể di chuyển lên trên, xuống dưới, sang trái, 
    
    sang phải khu vực bên cạnh, và không thể vượt qua được hàng rào.

    Hai chú cừu A và B được gọi là ‘xa cách’ nếu như chúng không thể 
    
    di chuyển tới vị trí của nhau. Các bạn hãy xác định xem số cặp 
    
    chú cừu xa cách bằng nhau nhiêu?

Input:  

    Dòng đầu tiên gồm 3 số nguyên dương N, K và M 
    
    (1 ≤  N ≤  100, K ≤  100, M ≤  N^2).  M dòng tiếp theo, mỗi dòng gồm 4 số nguyên u, v, x, y cho biết có rào chắn ở giữa hai khu vực (u, v) và (x, y) (2 ô này cạnh nhau). K dòng cuối, mỗi dòng chứa 2 số nguyên là tọa độ của mỗi chú cừu.

Output: 

    In ra số cặp chú cừu bị xa cách tìm được.


    C:\Users\ADMIN\Downloads\download (4).png
*/

#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
struct sv
{
    bool l, r, d, t, access;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> k >> m;
    int A[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            A[i][j] = 0;
    }
    sv used[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            used[i][j].access = used[i][j].d = used[i][j].l = used[i][j].r = used[i][j].t = true;
        }
    }
    while (m--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        if (d > b)
            used[a][b].r = false, used[c][d].l = false;
        else if (d < b)
            used[a][b].l = false, used[c][d].r = false;
        else if (c > a)
            used[a][b].d = false, used[c][d].t = false;
        else if (c < a)
            used[a][b].t = false, used[c][d].d = false;
    }
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        A[x - 1][y - 1] = 1;
    }
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (used[i][j].access)
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                used[i][j].access = false;
                int cntsheep = 0;
                while (q.size())
                {
                    pair<int, int> x = q.front();
                    q.pop();
                    int th = x.first, tt = x.second; // th = truc hoanh , tt = truc tung
                    if (A[th][tt])
                        cntsheep++;
                    for (int k = 0; k < 4; k++)
                    {
                        int I = th + dx[k], J = tt + dy[k];
                        if (k == 0 && I >= 0 && I < n && J >= 0 && J < n && used[I][J].d && used[I][J].access)
                            q.push({I, J}), used[I][J].access = false;
                        //
                        else if (k == 1 && I >= 0 && I < n && J >= 0 && J < n && used[I][J].l && used[I][J].access)
                            q.push({I, J}), used[I][J].access = false;
                        //
                        else if (k == 2 && I >= 0 && I < n && J >= 0 && J < n && used[I][J].t && used[I][J].access)
                            q.push({I, J}), used[I][J].access = false;
                        //
                        else if (k == 3 && I >= 0 && I < n && J >= 0 && J < n && used[I][J].r && used[I][J].access)
                            q.push({I, J}), used[I][J].access = false;
                    }
                }
                if (cntsheep)
                    v.push_back(cntsheep);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
            ans += v[i] * v[j];
    }
    cout << ans;
}