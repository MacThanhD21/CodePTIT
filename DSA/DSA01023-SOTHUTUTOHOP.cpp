
/*
    Cho một tổ hợp chập K của N số nguyên dương đầu tiên (2 < K < N < 15).

    Hãy xác định xem đó là tổ hợp thứ bao nhiêu nếu liệt kê tất cả các 

    tổ hợp theo thứ tự tăng dần (tính từ 1).

Input

    Dòng đầu ghi số T là số bộ test (T < 10)

    Mỗi bộ test gồm 2 dòng

    Dòng đầu ghi 2 số nguyên dương N và K (2 < K < N < 15)

    Dòng tiếp theo ghi một tổ hợp chập K của các số nguyên dương từ 1 đến N.  

Output

    Với mỗi bộ test, ghi ra trên một dòng số thứ tự của tổ hợp 

    (tính từ 1, theo thứ tự liệt kê tăng dần).

Ví dụ:

Input           Output

2

6 4

1 3 5 6         9

6 4

2 3 4 6         12

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pii pair<int, int>
#define fi first
#define se second

int n, k, a[1001], x[1001];

vector<vector<int>> v;

int check(vector<int> a, int b[], int k)
{
    for (int i = 0; i < k; ++i)
    {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

void Try(int i)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; ++j)
    {
        x[i] = j;
        if (i == k)
        {
            vector<int> tmp;
            for (int i = 1; i <= k; ++i)
                tmp.push_back(x[i]);
            v.push_back(tmp);
        }
        else
            Try(i + 1);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tt;
    cin >> tt;
    while (tt-- > 0)
    {
        cin >> n >> k;
        for (int i = 0; i < k; ++i)
            cin >> a[i];
        Try(1);
        int cnt = 0;
        for (auto it : v)
        {
            ++cnt;
            if (check(it, a, k))
            {
                cout << cnt << "\n";
                break;
            }
        }
    }
}
