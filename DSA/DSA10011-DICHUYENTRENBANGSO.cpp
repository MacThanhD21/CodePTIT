

/*

    Cho một bảng số kích thước N x M. Chi phí khi đi qua ô (i,j) 
    
    bằng A[i][j]. Nhiệm vụ của bạn là hãy tìm một đường đi từ ô (1, 1) 
    
    tới ô (N, M) sao cho chi phí là nhỏ nhất. Tại mỗi ô, bạn được phép đi 
    
    sang trái, sang phải, đi lên trên và xuống dưới.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test bắt đầu bởi hai số nguyên N và M (1 ≤ N, M ≤ 500).

    N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j] (0 ≤ A[i][j] ≤ 9).

Output: 

    Với mỗi test, in ra một số nguyên là chi phí nhỏ nhất cho đường đi tìm được.

Ví dụ:

Input                   Output

3

4

5                       24

0 3 1 2 9

7 3 4 9 9

1 7 5 5 3

2 3 4 2 5

1

6                       15

0 1 2 3 4 5

5 5

1 1 1 9 9               13

9 9 1 9 9

1 1 1 9 9

1 9 9 9 9

1 1 1 1 1


*/


#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ii pair<int, int>

const int N = 505;
const int INF = 1e9;

int n, m;
int a[N][N];
int disc[N][N]; // luu lai khoang cach nho nhat tu dinh s,t -> i, j
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            disc[i][j] = INF;
        }
    }
}

void DiJKSTRA(int s, int t)
{

    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> Q;
    Q.push({a[s][t], {s, t}});
    disc[s][t] = a[s][t];

    while (!Q.empty())
    {
        auto top = Q.top();
        Q.pop();

        auto disTance = top.first; // gia tri tren bang so
        auto toado = top.second;
        // if(disTance > d[u])
        //     continue;
        int I = toado.first, J = toado.second;
        for (int k = 0; k < 4; k++)
        {
            int I1 = I + dx[k];
            int J1 = J + dy[k];
            if (I1 >= 1 && J1 >= 1 && I1 <= n && J1 <= m && disc[I1][J1] > disTance + a[I1][J1])
            {
                disc[I1][J1] = disTance + a[I1][J1];
                Q.push({disc[I1][J1], {I1, J1}});
            }
        }
    }
    cout << disc[n][m] << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        init();
        DiJKSTRA(1, 1);
    }
}