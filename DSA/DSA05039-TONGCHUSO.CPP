
/*

    Cho hai số nguyên dương A và B. Tìm số N nhỏ nhất thỏa mãn:

    A là tổng các chữ số của N, B là tổng bình phương các chữ số của N.

    Nếu không tồn tại N thỏa mãn A và B hãy đưa ra -1. Giả thiết N có

    không quá 100 chữ số.

    Ví dụ với A = 18, B = 162 ta tìm được số nhỏ nhất

    N=99 vì 9+9=18 và 92 + 92 = 162. Với A = 12, B = 9 ta có kết quả  là -1.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test.

    Mỗi bộ test là cặp số A, B được viết trên một dòng.

    T, A, B thỏa mãn ràng buộc: 1≤T≤100;  1≤A≤100; 1≤B≤10000.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input           Output

2
18  162         99
12  9           -1


*/

#include <iostream>
using namespace std;

#define ll long long
int dp[101][10005];
int a, b;

inline void back(int a, int b)
{
    if (a < 0 || b < 0)
    {
        dp[a][b] = 1e9;
        return;
    }
    int ans = 1e9;
    for (int i = 1; i <= 9; i++)
    {
        int x = a - i, y = b - i * i;
        if (x < 0 || y < 0)
            continue;
        if (dp[x][y] == -1)
            back(x, y);
        ans = min(ans, dp[x][y]);
    }
    if (ans == 1e9)
        dp[a][b] = 1e9;
    else
        dp[a][b] = 1 + ans;
}
inline void solve()
{
    cin >> a >> b;
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
            dp[i][j] = -1;
    }
    dp[0][0] = 0;
    if (a == 0 && b == 0)
    {
        cout << 0 << "\n";
        return;
    }
    back(a, b);
    if (dp[a][b] == 1e9)
    {
        cout << -1 << "\n";
        return;
    }
    while (a > 0)
    {
        int minn = 1e9;
        for (int i = 1; i <= 9; i++)
        {
            int x = a - i;
            int y = b - i * i;
            if (x < 0 || y < 0)
                continue;
            minn = min(minn, dp[x][y]);
        }
        for (int i = 1; i <= 9; i++)
        {
            int x = a - i;
            int y = b - i * i;
            if (x < 0 || y < 0)
                continue;
            if (x >= 0 && y >= 0 && dp[x][y] == minn)
            {
                cout << i;
                a -= i;
                b -= i * i;
                break;
            }
        }
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

// CACH 2

// #include <bits/stdc++.h>
// using namespace std;

// int n, k;
// string s;
// long mod = 1e9 + 7;

// int p1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
// int p2[] = {1, 4, 9, 16, 25, 36, 49, 64, 81};

// pair<int, pair<int, int>> m[101][10001];
// int ok;

// void ktao()
// {
//     queue<pair<pair<int, int>, pair<int, int>>> q;
//     q.push({{0, 0}, {0, 0}}); // pair dau luu vtri hien tai, psau luu vtri truoc do
//     while (!q.empty())
//     {
//         auto a = q.front();
//         q.pop();
//         for (int i = 0; i < 9; i++)
//         {
//             int x = a.first.first + p1[i];
//             int y = a.first.second + p2[i];
//             if (x <= 100 && y <= 10000 && m[x][y].first == 0)
//             {
//                 m[x][y].first = p1[i];
//                 m[x][y].second = {a.first.first, a.first.second};
//                 q.push({{x, y}, {a.first.first, a.first.second}});
//             }
//         }
//     }
// }

// void find(int n, int k)
// {
//     if (m[n][k].first == 0)
//     {
//         if (ok == 0)
//             s += "-1";
//         return;
//     }
//     ok = 1;
//     s += char(m[n][k].first + 48);
//     find(m[n][k].second.first, m[n][k].second.second);
// }

// int main()
// {

//     ktao();
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         ok = 0;
//         s = "";
//         cin >> n >> k;
//         find(n, k);
//         sort(s.begin(), s.end());
//         cout << s;
//         cout << "\n";
//     }
// }