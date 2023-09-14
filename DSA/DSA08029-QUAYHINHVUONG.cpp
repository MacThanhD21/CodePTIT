
/*

    Có một chiếc bảng hình chữ nhật với 6 miếng ghép, trên mỗi miếng ghép 

    được điền một số nguyên trong khoảng từ 1 đến 6. Tại mỗi bước, 

    chọn một hình vuông (bên trái hoặc bên phải), rồi quay theo chiều kim đồng hồ.

    C:\Users\ADMIN\Downloads\download (3).png


    Yêu cầu: Cho một trạng thái của bảng, hãy tính số phép biến đổi 

    ít nhất để đưa bảng đến trạng thái đích.

Input:

    Dòng đầu ghi số bộ test (không quá 10). Mỗi bộ test gồm hai dòng:

    Dòng đầu tiên chứa 6 số là trạng thái bảng ban đầu 
    
    (thứ tự từ trái qua phải, dòng 1 tới dòng 2).

    Dòng thứ hai chứa 6 số là trạng thái bảng đích 
    
    (thứ tự từ trái qua phải, dòng 1 tới dòng 2).
Output: 

    Với mỗi test, in ra một số nguyên là đáp số của bài toán.

Ví dụ:

Input               Output

1

1 2 3 4 5 6         2
4 1 2 6 5 3

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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void rotateLeft(string &s)
{
    char c0 = s[0], c1 = s[1], c3 = s[3], c4 = s[4];
    s[0] = c3;
    s[1] = c0;
    s[4] = c1;
    s[3] = c4;
}
void rotateRight(string &s)
{
    char c1 = s[1], c2 = s[2], c4 = s[4], c5 = s[5];
    s[1] = c4;
    s[2] = c1;
    s[5] = c2;
    s[4] = c5;
}

map<string, int> mp;

void solve()
{
    mp.clear();
    string X, Y;
    for (int i = 1; i <= 6; i++)
    {
        int x;
        cin >> x;
        X += to_string(x);
    }
    for (int i = 1; i <= 6; i++)
    {
        int y;
        cin >> y;
        Y += to_string(y);
    }
    // cout << X << " " << Y << "\n";
    queue<pair<string, int>> Q;
    Q.push({X, 0});
    mp[X] = true;
    rotateLeft(X);
    // cout << X << "\n";
    while (Q.size())
    {
        auto top = Q.front();
        Q.pop();

        string u = top.first;
        int coun = top.second;

        if (u == Y)
        {
            cout << coun << "\n";
            return;
        }
        string tmp1, tmp2;
        tmp1 = u;
        tmp2 = u;

        rotateLeft(tmp1);
        if (!mp[tmp1])
        {
            Q.push({tmp1, coun + 1});
            mp[tmp1] = true;
        }
        rotateRight(tmp2);
        if (!mp[tmp2])
        {
            Q.push({tmp2, coun + 1});
            mp[tmp2] = true;
        }
    }
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
