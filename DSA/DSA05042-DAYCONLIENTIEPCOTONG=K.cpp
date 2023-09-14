
/*

    Cho dãy số A[] gồm có N phần tử không âm và số K.

    Nhiệm vụ của bạn là hãy xác định xem có tìm được 1 dãy con liên tiếp 
    
    mà tổng các phần tử bằng K hay không?

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm số nguyên N và K (1≤ N ≤ 100 000, 0 ≤ K ≤ 1018).

    Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 109).

Output: 

    Với mỗi test, in ra trên một dòng là đáp án thu được. 
    
    Nếu có hãy in ra “YES”. Nếu không tìm được đáp án, in ra “NO”.

Ví dụ:

Input:              Output

3

6 33

1 4 20 3 10 5       YES

7 7

1 4 0 0 3 10 5      YES

2 0

1 4                 NO

*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int T, N;
ll K, a[MAXN], dp[MAXN];
unordered_set<ll> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        for (int i = 1; i <= N; ++i)
            cin >> a[i];
        s.clear();
        s.insert(0);
        dp[0] = 0;
        bool flag = false;
        for (int i = 1; i <= N; ++i)
        {
            dp[i] = dp[i - 1] + a[i];
            if (s.find(dp[i] - K) != s.end())
            {
                cout << "YES\n";
                flag = true;
                break;
            }
            s.insert(dp[i]);
        }
        if (!flag)
            cout << "NO\n";
    }
    return 0;
}