
/*

    Cho dãy số A[] gồm có N phần tử.  Một dãy con liên tiếp được 
    
    gọi là dãy tam giác nếu như dãy đó tăng dần rồi lại giảm dần,
    
    hay tồn tại i, j, k sao cho A[i] ≤ A[i+1] ≤ … ≤ A[k] ≥ A[k+1] ≥ … ≥ A[j].

    Nhiệm vụ của bạn là hãy tìm dãy con liên tiếp là dãy tam giác có độ dài lớn nhất.

    Lưu ý: Dãy đơn điệu không giảm hoặc không tăng cũng là dãy tam giác. 
    
    Ví dụ A[] = {10, 20, 30, 40} là một dãy tam giác.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

    Mỗi test gồm số nguyên N(1≤ N ≤ 100 000).

    Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 106).

Output: 

    Với mỗi test, in ra trên một dòng là 
    
    độ dài của dãy con tìm được.

Ví dụ:

Input                   Output

2

6

12 4 78 90 45 23        5

8

20 4 1 2 3 4 2 10       5

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    int a[n * 2];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> triangle1(n + 1, 1), triangle2(n + 1, 1);

    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] < a[i])
            triangle1[i] = triangle1[i - 1] + 1;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] > a[i + 1])
            triangle2[i] = triangle2[i + 1] + 1;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, 1ll * triangle1[i] + triangle2[i] - 1);
    }
    cout << ans << "\n";
    // for(auto x : triangle1) cout << x << " "; cout << "\n";
    // for(auto x : triangle2) cout << x << " "; cout << "\n";
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}