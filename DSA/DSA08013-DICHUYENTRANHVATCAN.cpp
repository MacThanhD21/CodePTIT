
/*

    Cho một bảng kích thước N x N, trong đó có các ô trống 
    
    ‘.’ và vật cản ‘X’. Các hàng và các cột được đánh số từ 0.

    Mỗi bước di chuyển, bạn có thể đi từ ô (x, y) tới ô 
    
    (u, v) nếu như 2 ô này nằm trên cùng một hàng hoặc một cột, 
    
    và không có vật cản nào ở giữa.

    Cho điểm xuất phát và điểm đích. Bạn hãy tính số bước di chuyển ít nhất?

Input:

    Dòng đầu ghi số bộ test (không quá 10). Mỗi test gồm:

    Dòng đầu tiên là số nguyên dương N (1 ≤ N ≤ 100).

    N dòng tiếp theo, mỗi dòng gồm N kí tự mô tả bảng.

    Cuối cùng là 4 số nguyên a, b, c, d với (a, b) 
    
    là tọa độ điểm xuất phát, (c, d) là tọa độ đích. 
    
    Dữ liệu đảm bảo hai vị trí này không phải là ô có vật cản.
 

Output: 

    Với mỗi test, in ra một số nguyên là đáp số của bài toán.
 

Ví dụ:

Input           Output

1

3

.X.

.X.             3

...

0 0 0 2

*/

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, b) for (int i = 0; i < b; i++)
#define PER(i, b) for (int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 166
#define debugArr(...) 166
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;
const int LOG = 12;

int n, m;
char a[MAX][MAX];
int ans = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int dxQuan_Ma[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dyQuan_Ma[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

struct Point
{
    int x, y, cnt = 0;
};

bool check(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < n && a[i][j] == '.';
}

void travel(Point U, Point V)
{
    U.cnt = 0;
    queue<Point> Q;
    Q.push(U);
    a[U.x][U.y] = 'X';
    while (!Q.empty())
    {
        Point p = Q.front();
        Q.pop();

        int x = p.x, y = p.y, z = p.cnt;

        if (x == V.x && y == V.y)
        {
            cout << z << "\n";
            return;
        }

        for (int i = x + 1; i < n; i++)
        {
            if (check(i, y))
            {
                Point P = {i, y, z + 1};
                Q.push(P);
                a[i][y] = 'X';
            }
            else
                break;
        }
        for (int i = x - 1; i >= 0; i--)
        {
            if (check(i, y))
            {
                Point P = {i, y, z + 1};
                Q.push(P);
                a[i][y] = 'X';
            }
            else
                break;
        }
        for (int i = y + 1; i < n; i++)
        {
            if (check(x, i))
            {
                Point P = {x, i, z + 1};
                Q.push(P);
                a[x][i] = 'X';
            }
            else
                break;
        }
        for (int i = y - 1; i < n; i++)
        {
            if (check(x, i))
            {
                Point P = {x, i, z + 1};
                Q.push(P);
                a[x][i] = 'X';
            }
            else
                break;
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    Point U, V;
    cin >> U.x >> U.y >> V.x >> V.y;
    travel(U, V);
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int TEST = 1;
    cin >> TEST;
    for (int test = 1; test <= TEST; test++)
    {
        solve();
    }
}