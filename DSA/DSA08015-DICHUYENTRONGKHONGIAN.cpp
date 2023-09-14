
/*

    Cho một hình hộp chữ nhật có kích thước A x B x C, 
    
    trong đó A là chiều cao, B là chiều rộng và C là chiều dài. 
    
    Mỗi ô có thể là một ô trống ‘.’ hoặc vật cản ‘#’.

    Mỗi bước, bạn được phép di chuyển sang một ô kề bên cạnh 
    
    (không được đi chéo). Nhiệm vụ của bạn là tìm đường đi ngắn nhất 
    
    bắt đầu ‘S’ tới vị trí kết thúc ‘E’.

Input:

    Dòng đầu tiên là số lượng bộ test T (1 ≤ N ≤ 50).

    Mỗi test bắt đầu bởi 3 số nguyên A, B, C (A, B, C ≤ 30).

    Tiếp theo là A khối, mỗi khối gồm B x C kí tự mô tả một 
    
    lát cắt của hình hộp chữ nhật. Giữa 2 khối có một dấu xuống dòng.

Output: 

    In ra một số nguyên là đường đi ngắn nhất từ S tới E. 
    
    Nếu không di chuyển được, in ra -1.
Ví dụ:

Input                           Output

2

3 4 5                           11  

S....

.###.

.##..

###.#

#####

#####

##.##

##...

#####

#####

#.###

####E

1 3 3                              -1

S##

#E#

###

*/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, q;
char a[35][35][35];
int s1, s2, s3, e1, e2, e3;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

bool used[35][35][35];

struct MOVE
{
    int i, j, k;
};

inline void solve()
{
    cin >> n >> m >> q;
    memset(used, false, sizeof(used));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < q; k++)
            {
                cin >> a[i][j][k];
                if (a[i][j][k] == 'S')
                {
                    a[i][j][k] = '.';
                    s1 = i;
                    s2 = j;
                    s3 = k;
                }
                else if (a[i][j][k] == 'E')
                {
                    a[i][j][k] = '.';
                    e1 = i;
                    e2 = j;
                    e3 = k;
                }
            }
        }
    }

    MOVE hello = {s1, s2, s3};
    queue<pair<MOVE, int>> Q;

    Q.push({hello, 0});
    used[s1][s2][s3] = true;

    while (!Q.empty())
    {
        auto tmp = Q.front();
        Q.pop();

        int ii = tmp.first.i, jj = tmp.first.j, kk = tmp.first.k;
        if (ii == e1 && jj == e2 && kk == e3)
        {
            cout << tmp.second << "\n";
            return;
        }

        for (int k = 0; k < 6; k++)
        {
            int I = ii + dx[k], J = jj + dy[k], K = kk + dz[k];

            if (I >= 0 && I < n && J >= 0 && J < m && K >= 0 && K < q && a[I][J][K] == '.' && used[I][J][K] == false)
            {
                used[I][J][K] = true;
                Q.push({{I, J, K}, tmp.second + 1});
            }
        }
    }
    cout << "-1\n";
}
signed int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}