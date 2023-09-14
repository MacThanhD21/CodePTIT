

/*

    John có một đàn bò. Một ngày đẹp trời, anh ta quyết định mua xe tải với

    khả năng chở được C kg (1000 ≤ C ≤ 25000) để đưa những con bò đi xem phim.

    Cho số con bò là N (20 ≤ N ≤ 100) và khối lượng w[i] của từng con (đều nhỏ hơn C),

    hãy cho biết khối lượng bò lớn nhất mà John có thể đưa đi xem phim là bao nhiêu.

Input:

    Dòng 1: 2 số nguyên C và N cách nhau bởi dấu cách

    Dòng 2..N+1:Ghi lần lượt các số nguyên: w[i]

Output:

    Một số nguyên là tổng khối lượng bò lớn nhất

    mà John có thể mang đi xem phim.
Ví dụ:

Input           Output

259 5           242

81

58

42

33

61

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int C, n;
    cin >> C >> n;
    int a[n];
    for (int &x : a)
        cin >> x;

    int dp[C + 1] = {0};
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = C; j >= a[i]; j--)
        {
            if (dp[j - a[i]] == 1)
            {
                dp[j] = 1;
            }
        }
    }
    // for(int i = 0; i < 100; i++) cout << dp[i] << " ";
    // cout << "\n";
    for (int i = C; i >= 0; i--)
    {
        if (dp[i])
        {
            cout << i << "\n";
            return 0;
        }
    }
}
