/*

    Cho ma trận A[M][N]. Nhiệm vụ của bạn là đếm tất cả các đường đi từ phần tử A[0][0] 

    đến phần tử A[M-1][N-1]. Bạn chỉ được phép dịch chuyển xuống dưới hoặc sang phải 

    phần tử liền kề với vị trí hiện tại.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 

    Mỗi bộ test gồm hai phần: phần thứ nhất là 

    hai số M, N tương ứng với số hàng và số cột của ma trận; 
    
    dòng tiếp theo đưa vào các phần tử của ma trận A[][]; 
    
    các số được viết cách nhau một vài khoảng trống.

    T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 1≤M, N, A[i][j]≤100.

Output:

    Đưa ra số cách di chuyển của mỗi test theo từng dòng.

    Giải thích test 1: Có 3 cách di chuyển là [1 4 5 6], [1 2 5 6] và [1 2 3 6].
 

Input               Output

2
2  3
1  2  3             3
4  5  6

2  2
1  2                2
3  4

*/



#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pb push_back

const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int n, m, a[105][105];
bool vis[105][105];
ll ans = 0;

void Back(int i, int j)
{
    if (i == n - 1 && j == m - 1)
    {
        ++ans;
    }
    if (i < n - 1 && a[i + 1][j])
    {
        vis[i + 1][j] = true;
        Back(i + 1, j);
        vis[i + 1][j] = false;
    }
    if (j < m - 1 && a[i][j + 1])
    {
        vis[i][j + 1] = true;
        Back(i, j + 1);
        vis[i][j + 1] = false;
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
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        Back(0, 0);
        cout << ans << "\n";
        ans = 0;
    }
}