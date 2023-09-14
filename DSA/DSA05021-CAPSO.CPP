
/*
    Cho N cặp số, trong đó số thứ nhất bao giờ cũng nhỏ hơn số thứ 2.

    Ta nói, cặp số <c, d> được gọi là theo sau cặp số <a,b> nếu b<c.

    Nhiệm vụ của bạn là tìm số lớn nhất chuỗi các cặp thỏa mãn ràng buộc trên.

    Ví dụ với các cặp {<5, 24>, <39, 60>, <15, 28>, <27, 40>, <50, 90>}

    ta có kết quả là 3 tương ứng với chuỗi các cặp {<5,24>, <27, 40>, <50, 90>}.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test.

    Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N

    là số cặp <a, b>; dòng tiếp theo đưa vào 2*N số là N

    cặp số <a, b>; các số được viết cách nhau một vài khoảng trống.

    T, N, a, b thỏa mãn ràng buộc: 1≤T≤100;  1≤N, a, b ≤100.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input                               Output

2
5
5  24 39 60 15 28 27 40 50 90       3
2
5 10 1 11                           1

*/

#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        pair<int, int> M[101];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> M[i].first >> M[i].second;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (M[i].first > M[j].first)
                    swap(M[i], M[j]);
        int dp[101];
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            int m = 0;
            for (int j = 0; j < i; j++)
            {
                if (M[i].first > M[j].second)
                    m = max(dp[j], m);
            }
            dp[i] += m;
            res = max(dp[i], res);
        }
        cout << res << endl;
    }
}